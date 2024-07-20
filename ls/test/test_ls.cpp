#include <dirent.h>
#include <gtest/gtest.h>

extern "C" {
  #include "../includes/ls.h"
}

TEST(ext_finder, PYTHON) {
  const char* ext = get_entry_ext("vim.py");
  EXPECT_STREQ(ext, "py");
}

TEST(ext_finder_, DIR) {
  const char* ext = get_entry_ext("vim");
  EXPECT_STREQ(ext, "");
}

TEST(ext_finder_, HIDDEN) {
  const char* ext = get_entry_ext(".vimrc");
  EXPECT_STREQ(ext, "");
}

TEST(dir_entry, FIRST) {
  DIR* curr_dir = opendir(".");
  
  const char* fname = get_dir_entry(curr_dir);

  EXPECT_STREQ(fname, ".");
}

// TEST(ls, MAIN) {
//   ls();
// }

// #ifdef TESTING 
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
// #endif 