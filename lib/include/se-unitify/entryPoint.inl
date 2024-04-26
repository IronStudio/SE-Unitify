#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

#include "se-unitify/tests.hpp"



std::map<std::string, std::function<void()>> se::unitify::Test::testFunctions {};
std::vector<std::string> splitString(const std::string &str, char delimiter);


int main(int argc, char **argv) {
	if (argc != 2)
		throw std::invalid_argument("You must provide 1 arguments to the tests");

	std::vector<std::string> wantedTests {splitString(std::string(argv[1]), ',')};

	for (const auto &wanted : wantedTests) {
		auto it {se::unitify::Test::testFunctions.find(wanted)};
		if (it == se::unitify::Test::testFunctions.end())
			throw std::invalid_argument("Can't run test '" + wanted + "' : it was not added to SE_UNITIFY_TESTS_LIST");

		it->second();
	}



	return EXIT_SUCCESS;
}



std::vector<std::string> splitString(const std::string &str, char delimiter) {
	std::stringstream stream {str};
	std::string segment {};
	std::vector<std::string> output {};

	while (std::getline(stream, segment, delimiter))
		output.push_back(segment);
	return output;
}