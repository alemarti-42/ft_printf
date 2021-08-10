/* ************************************************************************** */
/*   TESTING                                                                  */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	void		*ptr;
	long int	ptr_n;
	int		res1 = 0;
	int		res2 = 0;
	int     a = -4;
	int     b = 0;
	char    c = 'a';
	int     d = 2147483647;
	int     e = -2147483648;
	int     f = 42;
	int     g = 25;
 	int     h = 4200;
	int     i = 8;
	int     j = -12;
	int     k = 123456789;
	int     l = 0;
	int     m = -12345678;
	char    *n = "abcdefghijklmnop";
	char    *o = "-a";
	char    *p = "-12";
	char    *q = "0";
	char    *r = "%%";
	char    *s = "-2147483648";
	char    *t = "0x12345678";
	char    *u = "-0";

// 	ptr = (void *)malloc(1);
// 	ptr_n = (long)ptr;
// /*
// 	ft_printf("\n----%s----\n", "1234");
// 	printf("\n----%s----\n\n", "1234");
// 	ft_printf("\n----%-s----\n", "1234");
// 	printf("\n----%-s----\n\n", "1234");
// 	ft_printf("\n----%10s----\n", "1234");
// 	printf("\n----%10s----\n\n", "1234");
// 	ft_printf("\n----%.s----\n", "1234");
// 	printf("\n----%.s----\n\n", "1234");
// 	ft_printf("\n----%.10s----\n", "1234");
// 	printf("\n----%.10s----\n\n", "1234");
// 	printf("\n|%d|\n", ft_printf("\n>>----%-20.4s----\n\n", "1234"));

// 	ft_printf("\n----%10c----\n\n", 66);
// 	printf("\n----%10c----\n\n", 66);
// 	ft_printf("\n----%-10c----\n\n", 66);
// 	printf("\n----%3p----\n\n", ptr);
// 	ft_printf("\n¿¿----%-10%----\n\n");
// //	ft_printf("\n----%010d----\n\n", 66);
// //	printf("\n----%010d----\n\n", 66);
// */



// //	STRING
// 	printf("\n\tSTRING\n");
// 	ft_printf("\n----%s----\n", "1234");
// 	printf("\n----%s----\n", "1234");
// 	ft_printf("\n----%.0s----\n", "1234");
// 	printf("\n----%.0s----\n", "1234");
// 	ft_printf("\n----%3.10s----\n", "1234");
// 	printf("\n----%3.10s----\n", "1234");
// 	ft_printf("\n----%3.3s----\n", "1234");
// 	printf("\n----%3.3s----\n", "1234");
// 	ft_printf("\n----%-6s----\n", "1234");
// 	printf("\n----%-6s----\n", "1234");
// /*
// // CHAR
// 	printf("\n\tCHAR\n");
// 	ft_printf("\n----%10.3c----\n\n", 66);
// 	ft_printf("\n----%-10.c----\n\n", 66);
// 	ft_printf("\n----%10c----\n\n", 66);
// */

// // DECIMAL
// 	printf("\n\tDECIMAL\n");
// 	printf("\n|%-.10d|\n", -66);
// 	ft_printf("\n|%-.10d|\n", -66);
// 	printf("\n|%010d|\n", -66);
// 	ft_printf("\n|%010d|\n", -66);
// 	printf("\n|%-.10d|\n", 66);
// 	ft_printf("\n|%-.10d|\n", 66);
// 	printf("\n|%010d|\n", 66);
// 	ft_printf("\n|%010d|\n", 66);
// 	printf("\n|%-10.d|\n", 66);
// 	ft_printf("\n|%-10.d|\n", 66);
// 	printf("\n|%010d|\n", -66);
// 	ft_printf("\n|%010d|\n", -66);
// 	printf("\n|%05d|\n", -666666);
// 	ft_printf("\n|%05d|\n", -666666);

// // UNSIGNED
// 	printf("\n\tUNSIGNED\n");
// 	printf("\n----%-10.30u----\n\n", 66);
// 	ft_printf("\n----%-10.30u----\n\n", 66);
// 	printf("\n----%-10.u----\n\n", 66);
// 	ft_printf("\n----%-10.u----\n\n", 66);
// 	printf("\n----%010u----\n\n", 66);
// 	ft_printf("\n----%010u----\n\n", 66);

// // HEXA
// 	printf ("\nHEXA:|%x|\n", 31);
// 	ft_printf ("\nHEXA:|%x|\n", 31);
// 	printf ("\nHEXA:|%10x|\n", 300000);
// 	ft_printf ("\nHEXA:|%10x|\n", 300000);
	

// // POINTER
// 	printf ("\nPUNTERO:|%p|\n", ptr);
// 	ft_printf ("\nPUNTERO:|%p|\n", ptr);
// 	printf ("\nPUNTERO:|%20p|\n", ptr);
// 	ft_printf ("\nPUNTERO:|%20p|\n", ptr);
/*
	res1 = printf("\n[1]B-IN:%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m,     n, c, c, j, j, j);
	res2 = ft_printf("\n[1]MINE:%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m,     n, c, c, j, j, j);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	printf("\n");
	res1 = printf("\n[2]B-IN:%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d);
	res2 = ft_printf("\n[2]MINE:%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	res1 = printf("\n[3]B-IN:%0i, %0d, %0d\n", i, j, k);
	res2 = ft_printf("\n[3]MINE:%0i, %0d, %0d\n", i, j, k);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	res1 = printf("\n[4]B-IN:%0i, %0d\n", i, j);
	res2 = ft_printf("\n[4]MINE:%0i, %0d\n", i, j);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	res1 = printf("\n[5]B-IN:%0i\n", i);
	res2 = ft_printf("\n[5]MINE:%0i\n", i);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	res1 = printf("\n[3]B-IN\n");
	res2 = ft_printf("\n[3]MINE\n");
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	printf("\n");
	res1 = printf("\n[7]B-IN:%i, %d, %d, %d, %d, %s, %c\n", i, j, k, l, m,     n, c);
	res2 = ft_printf("\n[7]MINE:%i, %d, %d, %d, %d, %s, %c\n", i, j, k, l, m,     n, c);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	printf("\n");
	
	res1 = printf("\n[7]B-IN:%2i, %2d, %2d, %2.5d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d);
	res2 = ft_printf("\n[7]MINE:%2i, %2d, %2d, %2.5d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	printf("\n");

	res1 = printf("\n[1]B-IN:%x, %X\n", j, j);
	res2 = ft_printf("\n[1]MINE:%x, %X\n", j, j);
	printf("\tBI:%d\tMI:%d\n", res1, res2);
	printf("\n");
	

	printf("\n|%d|\n", printf("%c", 0));
	printf("\n|%d|\n", ft_printf("%c", 0));
*/
	printf("\n|%d|\n", printf("%c", '0'));
	printf("\n|%d|\n", ft_printf("%c", '0'));

//	system("leaks test.out");

	return (0);
}
