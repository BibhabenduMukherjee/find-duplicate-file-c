#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>  
int main(int args , char **argss){
    const char *dir_path = ".";
    DIR *dir = opendir(dir_path);
    //check if a directory exists
    if(dir == NULL){
        fprintf(stderr,"Could not open directory");
        exit(1);
    }

    closedir(dir);
    // used in C to read the next directory entry from the directory 
    // represented by the dir pointer
    struct dirent *ent = readdir(dir);
    while(ent != NULL){
        // maximum 256 it can able to work
        printf("%s: ", ent->d_name);
        ent = readdir(dir);
    }
    return 0;
}