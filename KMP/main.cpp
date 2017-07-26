#include <iostream>
#include "kmp.h"
#include <string>

int main() {
	char a[] = "heslelo";
	std::string b = "le";
	std::cout << adsa::search(a, a + 7, b.begin(), b.begin() + 2);
}