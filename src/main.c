#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "linux/i2c-dev.h"
#include "bme680.h"

int main() {
  int bme_fd  = open("/dev/i2c-1", O_RDWR);
  if (bme_fd < 0) {
    printf("can't open device: %d\n", bme_fd);
    return -1;
  }

  // this ioctl sets any read or writes to bme_fd to use the i2c slave addr 0x77
  if (ioctl(bme_fd, I2C_SLAVE, bme_dev_addr) < 0) {
    printf("can't call ioctl");
    return -1;
  }

  printf("this the bme fd: %d\n", bme_fd);
  return 0;
}
