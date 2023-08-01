#include <stdio.h>

// Needed to check for directory exists
#include <dirent.h>
#include <errno.h>

// Constants
#define PATH_TO_INTERFACES "/sys/devices/virtual/net"
#define STR_BUFFER_LEN 40

int main(int argc, char **argv)
{
  // Variables
  DIR *dir;
  char bufferString[STR_BUFFER_LEN];

  // Construct path of VPN interface
  snprintf(bufferString, sizeof(bufferString), "%s/%s", PATH_TO_INTERFACES,
           argv[1]);

  dir = opendir(bufferString);

  if (dir)
  {
    /* Directory exists. */
    printf("{\"text\": \"🔐 %s\"}", argv[1]);
    closedir(dir);
  }
  else if (ENOENT == errno)
  {
    /* Directory does not exist. */
    printf("{\"text\": \"🔓 No VPN\",\"class\": \"down\"}");
  }

  return 0;
}