#include "quickselect.h"
#include <iostream>
#include <string>

int main() {
	std::string a[] = { "hello", "my", "abra", "boy", "cat" };
	int key;
	for (int i = 0; i < 5; i++) {
		key = adsa::nth_element(a, a + 5, i) - a;
		std::cout << key << "\n";
	}
}
