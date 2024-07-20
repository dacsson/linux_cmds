#include "../includes/ls.h"

char* get_dir_entry(DIR* curr_dir) {
  struct dirent* entry = readdir(curr_dir);

  if(entry != NULL) return entry->d_name;
  else return NULL;
}

const char* get_entry_ext(const char *filename) {
  const char *ext = strrchr(filename, '.');

  if(!ext || ext == filename) return "";
  return ext + 1;
}

void ls()
{
  DIR* curr_dir;
  struct dirent* entry;
  curr_dir = opendir(".");
  
  // end of dir
  bool eod = false;

  while(!eod) {
    const char* fname = get_dir_entry(curr_dir);
    if(fname == NULL) eod = true;
    else {
      const char* ext = get_entry_ext(fname);
      char* color = "";

      if(strcmp(ext, "py") == 0) color = "\033[0;31m";
      else if(strcmp(ext, "o") == 0) color = "\033[0;32m";
      
      printf("%s %s \033[0m \n", color, fname);
    }
  }
}

// #ifndef TESTING
// int main(int argc, char **argv)
// {
  

//   return 0;
// }
// #endif