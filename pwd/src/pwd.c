#include "../includes/pwd.h"

const char* pwd() {
  char* rel_path = ".";
  char actual_apth[PATH_MAX+1];
  char* full_path;

  full_path = realpath(rel_path, actual_apth);

  return full_path;
}