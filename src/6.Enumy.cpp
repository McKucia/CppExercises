
#include <iostream>

enum Colors1 {
	RED,
	BLUE,
	GREEN
};

enum {
	beznazwy
};

// we cannot put the same names
// enum TrafficLight1 {
// 	GREEN,  
// 	YELLOW, 
// 	RED  
// };

// with enum class we can
enum class Colors2 {
	RED,
	BLUE,
	GREEN
};

enum class TrafficLight2 {
	GREEN,  
	YELLOW, 
	RED  
};

int main() {
	auto lightColor1 = 2;

	if (lightColor1 == RED) // 2 or 0 ?
		std::cout << "red" << std::endl;
	else 
		std::cout << "not red" << std::endl;

	if (lightColor1 == static_cast<int>(Colors2::GREEN)) // 2 or 0 ?
		std::cout << "red" << std::endl;
	else
		std::cout << "not red" << std::endl;
    return 0;
}