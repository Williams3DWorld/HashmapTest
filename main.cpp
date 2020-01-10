#include <iostream>
#include <unordered_map>	// Used to look up values by keys (keys are immutable once assigned) - uses red-black tree: O(1) access time
#include <unordered_set>	// Used to contain a set of values (values are mutable) - uses red-black tree: O(1) access time
#include <vector>			// Great for using the swap-and-pop method, however element access may be slower

/* Custom struct */
struct test
{
	int value;

	explicit test(int t)
	{
		value = t;
	}
};

/* Main Entry Point */
int main(int argc, char** argv)
{
	std::unordered_map<int, const test*> usernames;		// O(n^3*2) Auxilary space

	/* Insertion - O(1) */
	usernames[2] = new test(7);
	usernames[0] = new test(3);
	usernames[1] = new test(1);

	std::cout << "KEY\tELEMENT\n";
	std::unordered_map<int, const test*>::iterator it;
	for (it = usernames.begin(); it != usernames.end(); it++)	// O(n)
		std::cout << it->first << "\t" << it->second->value << "\n";

	std::cout << "\n";

	std::cout << "VALUE FROM KEY 2: " << usernames.at(2)->value << "\n";	// O(1)
	std::cout << "BUCKET NUMBER HOLDING KEY 1: " << usernames.bucket(1) << "\n";	// O(1)
	std::cout << "BUCKET COUNT: " << usernames.bucket_count() << "\n";	// O(1)
	std::cout << "NUM ELEMENTS IN BUCKET 5: " << usernames.bucket_size(5) << "\n";	// O(1)	
	std::cout << "KEY 2 IS PRESENT IN MAP: " << usernames.count(2) << "\n";	// O(1)

	std::cout << "\nEQUAL RANGE (0, 1, 2)\n";

	/* O(n^2) */
	for (unsigned j = 0; j != 3; ++j)
	{
		auto range = usernames.equal_range(j);	// O(1)
		for (auto i = range.first; i != range.second; i++)
			std::cout << i->first << "\t" << i->second->value << "\n";
	}

	std::cout << "\n";
	system("PAUSE");

	return EXIT_SUCCESS;
}