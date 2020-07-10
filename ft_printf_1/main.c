#include "header.h"
#include <stdio.h>

int main()
{
	int a = 1;//printf("%%04.5i 42 == |%04.5i|\n", 42);
	int b = ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	ft_printf("%013ia\n", -2147483648);
	ft_printf("%-15.13ia\n", -2147483648);
	ft_printf("%-i\n", -2147483648);
	ft_printf("Kashim a %u histoires à raconter\n", 1001);
	ft_printf("%d %d\n", a, b);
}

/*
cspdiuxX%  -0.*
s p % - 0 .*
d i c u x X
*/
