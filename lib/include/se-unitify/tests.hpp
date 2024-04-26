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



#define SE_UNITIFY_CREATE_TEST(name) void testFunctionScope_##name() {
#define SE_UNITIFY_CREATE_TEST_END(name) }\
static se::unitify::Test testAdder_##name {#name, &testFunctionScope_##name};

