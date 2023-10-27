#define _DEFAULT_SOURCE
#include <stdio.h>
#include <assert.h>
#include <dirent.h>
#include <stdlib.h>  
#define PATH_SEP "/"
#define PATH_SEP_LEN (sizeof(PATH_SEP)-1)
char *join_path(const char*base , const char *file){
        size_t base_len = strlen(base);
        size_t file_len = strlen(file);
        char *result = malloc(base_len+file_len+ PATH_SEP_LEN +1);
        assert(result != NULL);
        char *end = result;
       
        memcpy(end, base , base_len);
        end+= base_len;
        memcpy(end, PATH_SEP , PATH_SEP_LEN);
        end += PATH_SEP_LEN
        memcpy(end, file , file_len);
        end += file_len;
        *end = '\0';
        return result;
}
void print_file_rec(const char *dir_path){
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
        if(ent->d_tyep == DT_DIR){
             char*child_path = join_path(dir_path  , ent->d_name)
             print_file_rec(child_path);
             printf("%s: ", ent->d_name);
             free(child_path);
        }else{
             printf("%s: ", ent->d_name);
        }
       
        ent = readdir(dir);
    }
    closedir(dir);
}



int main(int args , char **argss){
    const char *dir_path = ".";
 
    return 0;
}
