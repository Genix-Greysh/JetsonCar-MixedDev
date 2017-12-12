#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
//#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
int uart_fd;
char *uart_name = "/dev/ttyTHS2"; // ttyTHS2 = Jetson UART1 located on Serial Port Header J17
char sample_test_uart[25] = {'S', 'A', 'M', 'P', 'L', 'E', '\n', '\r'};
struct termios uart_attr;
uart_attr.c_ospeed = 0;

if(argc > 1) uart_name = argv[1];

uart_fd = open(uart_name, O_RDWR | O_NONBLOCK | O_NOCTTY); //

if(uart_fd < 0){
printf("error opening UART %s, aborting..\n", uart_name);
return uart_fd;
}

if(tcgetattr(uart_fd, &uart_attr) < 0) {
printf("failed to read uart attibute, aborting \n");
return uart_fd; }

printf("UART speed is %d\n", uart_attr.c_ospeed);

//cfsetspeed(&uart_attr, B38400);
cfsetspeed(&uart_attr, B921600);
printf("B38400 is %d\n", B38400);
printf("B921600 is %d\n", B921600);

//uart_attr.c_ospeed = B38400;
//uart_attr.c_ispeed = B38400;

if(tcsetattr(uart_fd, TCSANOW, &uart_attr) < 0) {
printf("failed to set uart attibute, aborting \n");
return uart_fd;
}

printf("writing to UART %s\n", uart_name);
int result = write(uart_fd, sample_test_uart, 8);

printf("write %d byte to UART\n", result);

int i = 0;
int ret = 0;
char a;
while (1) {
	ret = read(uart_fd, &a, 1);
	if (ret > 0) {
		printf("Received: %c\n", a);
		i++;
		if (a == 0x03) break; // CTRL+C (EXIT)
	}
}

close(uart_fd);
}
