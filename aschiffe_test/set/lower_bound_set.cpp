#include "test_set.hpp"

/* iterator lower_bound (const value_type& val) const; */

static int test_count = 0;

void
lower_bound_set_test()
{
	FT_SET		ft_set;
	STD_SET		std_set;
	STD_VECTOR  ft_output;
	STD_VECTOR  std_output;
	for (int i = 0; i < 10000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
	FT_SET::iterator	    ft_rtvl;
	STD_SET::iterator	    std_rtvl;
	ft_rtvl = ft_set.lower_bound(500);
	std_rtvl = std_set.lower_bound(500);
	verify_content(ft_output, std_output, ++test_count);
}

template<typename ContainerType>
void
lower_bound_speed_test(ContainerType& x)
{
	x.lower_bound(500);
}

void
intro()
{
	std::cout << "==============================lower_bound===================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_SET  ft_set;
	STD_SET std_set;
    for (int i = 0; i < 1000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
    srand(time(NULL));
	measure_handler(ft_set, std_set, &lower_bound_speed_test, &lower_bound_speed_test);
	lower_bound_set_test();
    return 0;
}