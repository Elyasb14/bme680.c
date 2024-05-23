#include "bme680.h"
#include "linux/i2c-dev.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  int bme_fd = open("/dev/i2c-1", O_RDWR);
  if (bme_fd < 0) {
    printf("can't open device: %d\n", bme_fd);
    return -1;
  }

  // this ioctl sets any read or writes to bme_fd to use the i2c slave addr 0x77
  if (ioctl(bme_fd, I2C_SLAVE, bme_dev_addr) < 0) {
    printf("can't call ioctl");
    return -1;
  }

  unsigned char temp_buf[32];
  int ret_code, res;

  // 0xd0 is the chip id register
  // write the reg addr to the bme_fd, read the result
  // result should be 0x61 (or 97)
  temp_buf[0] = 0xd0;
  ret_code = write(bme_fd, temp_buf, 1);
  res = read(bme_fd, temp_buf, 1);
  if (temp_buf[0] != 97 || ret_code < 0 || res != 1) {
    printf("%d is the wrong chip id", temp_buf[0]);
    return -1;
  }
  return 0;
}
