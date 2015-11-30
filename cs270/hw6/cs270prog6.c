/*      Jonathan Buch
        CS270
        prog6.c
        November 19th, 2015
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>  // stat()
#include <time.h>      // ctime()
#include <dirent.h>    // opendir()

//#include <ndir.h>       // PATH_MAX
int asciicheck(unsigned char *);

int main(int argc, char *argv[])
{
        FILE *filen;
        DIR *dirp;
        unsigned char firstchars[100];
        struct stat stat_buf;
        struct dirent *dirpoint;
        dirp = opendir(".");
        while ((dirpoint = readdir(dirp)) != NULL)
        {
                if (stat(dirpoint->d_name, &stat_buf) == -1) {
                        exit(1);
                }
                // Check if an option has been supplied
                if (argc == 2) {
                        // Which option string is supplied?
                        if (strcmp (argv[1], "-t") == 0){
                                // -t option (Dates and Times of each file)
                                // stat(const char* name, struct stat* buf) system call (Need st_atime, st_mtime, st_ctime) with opendir()
                                printf("Filename: %s, ", dirpoint->d_name);
                                printf("Last Access Time: %s ******* Last Modified Time: %s ******* Last Status Change Time: %s\n", 
                                        ctime(&stat_buf.st_atime), ctime(&stat_buf.st_mtime), ctime(&stat_buf.st_ctime));
                        }
                        // -f option (Guessy
                }
                // Print names of the files in the current directory (ls)
                else {
                        printf("%s\n", dirpoint->d_name);
                }
        }
        closedir(dirp);
}

int asciicheck(unsigned char *string) {
        printf("asciicheck got this string: %s\n", string);
        int i;
        int length = strlen(string);
        for(i = 0; i < length; i++) {
                printf("%d", string[i]);
                if (string[i] > 127) {
                        return 0;
                }
        }
        return 1;
}
                