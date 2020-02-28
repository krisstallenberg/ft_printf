/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testfile.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 19:02:08 by kstallen      #+#    #+#                 */
/*   Updated: 2020/01/25 15:45:44 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//////* LIBRARIES *//////

#include <stdio.h>
#include <libc.h>
#include <limits.h>

//////* CUSTOM TESTS *//////
#define TEST1 "%s", "test 1"
#define TEST2 "%s\n", "test2"
#define TEST3 "%s\t%s", "test", " 3"
#define TEST4 "%i.5", 912300123

//////* DEFINE FLAGS *//////

#define FLAGS "-0.*"
#define BONUS_FLAGS "#’ +"

///////* CONVERSIONS *//////

#define CONVERSIONS "cspdiuxX%"

//////* COLORS *//////

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

typedef	struct			s_test_case
{
	void				*arg_type;
	void				*fl_expgs;
	void				*input;
	int					length_a;
	int					length_b;
	void				*output_exp;
	void				*output_act;
	int					result;
	struct	s_test_case	*next_test;
}						t_test_case;

t_test_case		*fill_struct(void *arg_type, void *fl_expgs, void *input, 
		void *output_exp, void *output_act, int length_a, int length_b,
		int result, t_test_case **head)
{
	t_test_case *new_case = (t_test_case *)malloc(sizeof(t_test_case));
	t_test_case *l_expst = *head;

	new_case->arg_type = arg_type;
	new_case->fl_expgs = fl_expgs;
	new_case->input = input;
	new_case->output_exp = output_exp;
	new_case->output_act = output_act;
	new_case->length_a = length_a;
	new_case->length_b = length_b;
	new_case->result = result;
	new_case->next_test = NULL;

	if (*head == NULL)
	{
		*head = new_case;
		return (*head);
	}
	while (l_expst->next_test != NULL)
		l_expst = l_expst->next_test;
	l_expst->next_test = new_case;
	return (*head);
}

t_test_case		*integer_testing(void)
{
	long		number = 1;
	int			l_exp = 0;
	int			l_act = 0;
	int			r = 0;
	void		*tempa = NULL;
	void		*tempb = NULL; 
	char		*flags = "FLAGS";
	t_test_case	*int_tests;

	int_tests = (t_test_case *)malloc(sizeof(t_test_case));
	while (*flags)
	{
		while (number <= 10000000000)
		{
			l_exp = printf("%i", (int)number);
			l_act = printf("%i", (int)number);				//insert ft_printf
	//		save stdout in tmp
			r = (memcmp(tempa, tempb, sizeof(tempa)));
			fill_struct(NULL, NULL, (void *)number, tempa, tempb, l_exp, l_act, r, &int_tests);
			number *= 10;
		}
		number *= -10;	
		while (number <= 0)
		{
			number /= 10;	
			l_exp = printf("%i", (int)number);
			l_act = printf("%i", (int)number);				//insert ft_printf
	//		stdout opsl_expan in temp en meegeven als output_exp & output_act
	//		result = (memcmp(tempa, tempb, sizeof(tempa)));
	//		fill_struct(NULL, NULL, l_exp, l_exp, number, tempa, tempb, result, NULL, int_tests)
			if (number == 0)
				break ;
		}
		flags++;
	}
	return (int_tests);
}
	
//int				result_printer(t_test_case **head)
//{
	// Reads a t_test_case list
	// If result == 1 --> green checkmark
	// If result == 0 --> red cross
	//
	// Save red crosses somehow,
	// then print
	// Total tests ran: 	xx
	// Correct results: 	xx/xx
	// Incorrect results:	xx/xx
	//
	// Expect:			-1
	// Actual:			1
	// Conversion type:	%i
	// Input:			-1
	// Flags:			.
	//
	// Expect:			-1
	// Actual:			1
	// Conversion type:	%i
	// Input:			-1
	// Flags:			. 
//}

int				main(void)
{
	int				l_exp = 0;
	int 			l_act = 0;
	t_test_case		*int_tests;

	printf(BOLDWHITE "\n\n--==============CUSTOM TEST 1===============--\n" RESET);
	printf(BOLDWHITE "Expect:\n" RESET);
	l_exp = printf(TEST1);
	printf(BOLDWHITE "\nActual:\n" RESET);
	l_act = printf(TEST1);								//insert ft_printf
	printf("\nret value expect: %i\nret value actual: %i\n", l_exp, l_act);
	if (l_exp == l_act)
		printf(BOLDGREEN "Same output, success!" RESET);
	else 
		printf(BOLDRED "Oops, something went wrong..." RESET);

	printf(BOLDWHITE "\n\n--==============CUSTOM TEST 2===============--\n" RESET);
	printf(BOLDWHITE "Expect:\n" RESET);
	l_exp = printf(TEST2);
	printf(BOLDWHITE "\nActual:\n" RESET);
	l_act = printf(TEST2);
	printf("\nret value expect: %i\nret value actual: %i\n", l_exp, l_act);
	if (l_exp == l_act)
		printf(BOLDGREEN "Same output, success!" RESET);
	else 
		printf(BOLDRED "Oops, something went wrong..." RESET);

	printf(BOLDWHITE "\n\n--==============CUSTOM TEST 3===============--\n" RESET);
	printf(BOLDWHITE "Expect:\n" RESET);
	l_exp = printf(TEST3);
	printf(BOLDWHITE "\nActual:\n" RESET);
	l_act = printf(TEST3);
	printf("\nret value expect: %i\nret value actual: %i\n", l_exp, l_act);
	if (l_exp == l_act)
		printf(BOLDGREEN "Same output, success!" RESET);
	else 
		printf(BOLDRED "Oops, something went wrong..." RESET);

	printf(BOLDWHITE "\n\n--==============CUSTOM TEST 4===============--\n" RESET);
	printf(BOLDWHITE "Expect:\n" RESET);
	l_exp = printf(TEST4);
	printf(BOLDWHITE "\nActual:\n" RESET);
	l_act = printf(TEST4);
	printf("\nret value expect: %i\nret value actual: %i\n", l_exp, l_act);
	if (l_exp == l_act)
		printf(BOLDGREEN "Same output, success!" RESET);
	else 
		printf(BOLDRED "Oops, something went wrong..." RESET);


	printf(BOLDWHITE "\n\n--==============Integer testing===============--\n" RESET);	
	int_tests = integer_testing();
	
	
	return (0);
}
