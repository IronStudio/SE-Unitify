#pragma once

#include <map>
#include <string>
#include <functional>



namespace se::unitify {
	class Test {
		public:
			inline Test(const std::string &name, const std::function<void()> &function) {
				testFunctions[name] = function;
			}

			static std::map<std::string, std::function<void()>> testFunctions;
	};
} // namespace se::unitify



#define SE_UNITIFY_CREATE_TEST(name) void testFunctionScope_##name() {\
	std::cout << "\033[35mStarting test '" << #name << "'\033[0m" << std::endl;\
	size_t __SE_UNITIFY_CHECK_COUNT {0};\
	size_t __SE_UNITIFY_PASSED_COUNT {0};
#define SE_UNITIFY_CREATE_TEST_END(name) if (__SE_UNITIFY_PASSED_COUNT != __SE_UNITIFY_CHECK_COUNT)\
	std::cout << "\033[31m" << #name << " failed : " << __SE_UNITIFY_PASSED_COUNT << " of " << __SE_UNITIFY_CHECK_COUNT << " succeded\033[0m" << std::endl;\
else\
	std::cout << "\033[32m" << #name << " succeded : " << __SE_UNITIFY_CHECK_COUNT << " tests in total\033[0m" << std::endl;\
}\
static se::unitify::Test testAdder_##name {#name, &testFunctionScope_##name};


#define SE_UNITIFY_CONDITION(cond) if (!(cond))\
	std::cerr << "\033[31mCheck " << __SE_UNITIFY_CHECK_COUNT + 1 << " not passed : " << #cond << "\033[0m" << std::endl;\
else ++__SE_UNITIFY_PASSED_COUNT;\
++__SE_UNITIFY_CHECK_COUNT

