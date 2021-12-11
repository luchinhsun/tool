#include <stdio.h>
#include <stdarg.h>

#define TEST_PRINTF(fmt, ...) test_printf("(%s, %d)"fmt"\n", __func__, __LINE__, ##__VA_ARGS__)

int test_printf(const char *p, ...)
{
	va_list args;

	va_start(args, p);
	vprintf(p, args);
	va_end(args);
}

int main()
{
	TEST_PRINTF("this is error log message %d %s", 1234, "HIHI");
	TEST_PRINTF("this is error log message %d %d %s", 5555, 556644, "ABCD");
	return 0;
}

// marco refer https://openhome.cc/Gossip/CGossip/Macro.html
