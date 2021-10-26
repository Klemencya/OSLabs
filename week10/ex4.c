#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void list_files(const char *mainPath){
    DIR *d1, *d2;
    struct dirent *dir1;
    struct stat s1;
    d1 = opendir(mainPath);
    if (d1) {
        while ((dir1 = readdir(d1)) != NULL){
            stat(dir1->d_name, &s1);
            if (strcmp(dir1->d_name, ".") != 0 && strcmp(dir1->d_name, "..") != 0 && s1.st_nlink >= 2
                                                                && strncmp(dir1->d_name, "link", 4) != 0) {
                printf("%s - ", dir1->d_name);
                struct dirent *dir2;
                struct stat s2;
                d2 = opendir(mainPath);
                while((dir2 = readdir(d2)) != NULL){
                    stat(dir2->d_name, &s2);
                    if (dir1->d_ino == dir2->d_ino && strcmp(dir1->d_name, dir2->d_name) != 0){
                        printf("%s ", dir2->d_name);
                    }
                }
                closedir(d2);
                printf("\n");
            }
        }
        closedir(d1);
    }
}

int main() {
    char path[1000];
    printf("Enter path to file: ");
    scanf("%s", path);

    list_files(path);
    return 0;
}
