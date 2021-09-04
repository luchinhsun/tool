#include <stdio.h>

void set_bit(unsigned char *target, int bit){
	*target |= (1 << bit);
}

void clean_bit(unsigned char *target, int bit){
	*target &= ~(1 << bit);
}

int main(){

	unsigned char test_val = 0xA5;//(10100101)

	printf("test_val %x (10100101)\n", test_val);

	set_bit(&test_val, 1);

	printf("set bit 1 with test_val %x\n", test_val);

	clean_bit(&test_val, 1);

	printf("clean bit 1 with test_val %x\n", test_val);

	char singed_val = 0xA5;//(10100101) -> ~(0100101) -> -(1011010) -> -(90+1)

	printf("singed_val A5 %d (10100101) -> ~(0100101) -> -(1011010) -> -(90+1)\n", singed_val);

	return 0;
}