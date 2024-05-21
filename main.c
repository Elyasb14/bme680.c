#include <fcntl.h>
#include <stdio.h>

#define debug


int main() {
  int bme_fd  = open("/dev/i2c-1", O_RDWR);

  printf("this the bme fd: %d", bme_fd);
}
