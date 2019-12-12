#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc != 2)
    write(2, "Error message", strlen("Error message"));

  int x = atoi(argv[1]);

  sleep(x);

  exit();
}
