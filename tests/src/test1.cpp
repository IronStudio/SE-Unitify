#include <iostream>

#include <se-unitify/se-unitify.hpp>



SE_UNITIFY_CREATE_TEST(test1)
	std::cout << "Hello from test1" << std::endl;
SE_UNITIFY_CREATE_TEST_END(test1)