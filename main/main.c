#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 512
#define MAX_CMD 512
#define MAX_NAME 128

const char *REPO =
    "https://raw.githubusercontent.com/JohanLiebert363/PackageManager/main";

const char *packages[] = {
    "funpkg-calc",
    "funpkg-notes",
    "funpkg-ping",
    "funpkg-random",
    "funpkg-sysinfo",
    "funpkg-time",
    "funpkg-weather",
    NULL
};


void ensure_dirs() {
    system("mkdir -p ~/.funpkgs/bin");
    system("mkdir -p /tmp/funpkg");
}

int github_download(const char *url, const char *out) {
    char cmd[MAX_CMD];
    sprintf(cmd, "curl -s -L \"%s\" -o \"%s\"", url, out);
    return system(cmd);
}

int package_exists(const char *pkg) {
    char url[MAX_URL];

    sprintf(url,
        "%s/%s/funpkg.json",
        REPO, pkg
    );

    return github_download(url, "/tmp/funpkg/check.json") == 0;
}

void list_packages() {
    printf("Available packages:\n");
    for (int i = 0; packages[i] != NULL; i++) {
        printf(" - %s\n", packages[i]);
    }
}

void install_package(const char *pkg) {
    char url[MAX_URL];
    char cmd[MAX_CMD];
    char pkgdir[MAX_NAME];

    sprintf(pkgdir, "/tmp/funpkg/%s", pkg);

    sprintf(cmd, "rm -rf %s && mkdir -p %s", pkgdir, pkgdir);
    system(cmd);

    sprintf(url, "%s/%s/funpkg.json", REPO, pkg);
    sprintf(cmd, "%s/funpkg.json", pkgdir);
    github_download(url, cmd);

    sprintf(url, "%s/%s/install.sh", REPO, pkg);
    sprintf(cmd, "%s/install.sh", pkgdir);
    github_download(url, cmd);
    system("chmod +x /tmp/funpkg/*/install.sh");


    char shortname[64];
    strcpy(shortname, pkg + 7); 

    sprintf(url, "%s/%s/%spkg.c", REPO, pkg, shortname);
    sprintf(cmd, "%s/%spkg.c", pkgdir, shortname);
    github_download(url, cmd);


    sprintf(cmd, "cd %s && ./install.sh", pkgdir);
    system(cmd);

    printf("✔ Installed %s\n", pkg);
}

int main() {
    ensure_dirs();

    char cmd[50];
    char pkg[50];

    printf("Fun Package Manager (funpm)\nType 'list' to see packages.\n\n");

    while (1) {
        printf("funpm> ");
        scanf("%49s", cmd);

        if (!strcmp(cmd, "exit"))
            break;

        if (!strcmp(cmd, "list")) {
            list_packages();
            continue;
        }

        if (!strcmp(cmd, "install")) {
            printf("Package: ");
            scanf("%49s", pkg);

            if (!package_exists(pkg)) {
                printf("❌ Package '%s' not found.\n", pkg);
                continue;
            }

            install_package(pkg);
            continue;
        }

        printf("Unknown command: %s\n", cmd);
    }

    return 0;
}
