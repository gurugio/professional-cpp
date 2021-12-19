// build: clang++ -std=c++2a a.cpp -lfmt

import<iostream>;
#include <limits>
#include <fmt/core.h>
#include <array>
#include <initializer_list>
#include <optional>

using namespace std;
using namespace fmt;

class MyClass
{
public:
	MyClass(int a, int b, int c, int d)
	{
		cout << "aaa\n";
		m_array[0] = a;
		m_array[1] = b;
		m_array[2] = c;
		m_array[3] = d;
	}
	MyClass() : m_array{0, 1, 2, 3} { cout << "bbb\n"; }

private:
	int m_array[4];
};

// optional<int> makeSum(initializer_list<int> values)
// {
// 	int total {0};
// 	for (int value: values) {
// 		if (value < 0) return {};
// 		total += value;
// 	}
// 	return total;
// }

const string message{"test"};
const string &foo() { return message; }

int main()
{
	int aaa{33};
	cout << aaa << endl;
	// cout << format("Max int: {}\n", aaa);

	//cout << makeSum({1,2,-3}).value_or(0) << endl;

	MyClass ccc(2, 2, 2, 2);
	MyClass ddd{2, 2, 2, 2};
	MyClass eee{};

	auto f1{foo()};
	const auto &f2{foo()};
}
