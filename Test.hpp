#include <iostream>
using namespace std;

#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "rang.hpp"
#include "zip.hpp"
#include "badkan.hpp"

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


		testcase.setname("Play with dummy choosers and guessers")
	
    .print(cout, /*show_grade=*/false);

    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}


