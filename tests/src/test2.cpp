#include <iostream>

#include <se-unitify/se-unitify.hpp>



SE_UNITIFY_CREATE_TEST(test2)
	std::cout << "Hello from test2" << std::endl;

	SE_UNITIFY_CONDITION(true);
	SE_UNITIFY_CONDITION(false);
	SE_UNITIFY_CONDITION(true);
	SE_UNITIFY_CONDITION(true);
SE_UNITIFY_CREATE_TEST_END(test2)