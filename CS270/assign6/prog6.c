/* 
	Jonathan Buch
        CS270
        prog6.c
        November 19th, 2015 
*/
#include <stdio.h> 
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h> 
#include <sys/types.h> 
#include <time.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
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
                        // -f option (Guess at each file type)
                        if (strcmp (argv[1], "-f") == 0) {
                                // Print filename before file type
                                printf("Filename: %s, ", dirpoint->d_name);
                                printf("Type: ");
                                // Open the file to read in the first line
                                filen = fopen(dirpoint->d_name, "r");
                                // Read first line
                                fgets(firstchars, sizeof(firstchars), filen);
                                fclose(filen);
                                // Post Script File
                                if (strstr(firstchars,"%!PS-Adobe")) {
                                        printf("PostScript File\n");
                                }
                                else {
                                        if (strstr(firstchars, "\r\n")) {
                                                printf("DOS File\n");
                                        }
                                        else {
                                                // ELF File
                                                if (firstchars[0] == 0x7f && firstchars[1] == 'E' && firstchars[2] == 'L' && firstchars[3] == 'F') {
                                                        printf("ELF File\n");
                                                }
                                                else {
                                                        // Regular ACSII File
                                                        if (asciicheck(firstchars)) {
                                                                printf("ACSII File\n");
                                                        }
                                                        // Otherwise, unidentifiable binary file
                                                        else {
                                                                printf("Binary File\n");
                                                        }
                                                }
                                        }
                                }
                        }
                }
                // Print names of the files in the current directory (ls)
                else {
                        printf("%s\n", dirpoint->d_name);
                }
        }
        closedir(dirp);
}
int asciicheck(unsigned char *string) {
        int i;
        int length = strlen(string);
        for(i = 0; i < length; i++) {
                if (string[i] > 127) {
                        return 0;
                }
        }
        return 1;
}
                
