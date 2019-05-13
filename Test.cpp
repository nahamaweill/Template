#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		
		testcase.setname("Range test");

		int help = 0;
		for (int i: range(0,35))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		help = 5;
		for (int i: range(5,7))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		help = -10;
		for (int i: range(-10,0))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		help = 101;

		for (int i: range(101,102))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		help = 2;

		for (int i: range(2,2))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		char helpC = 'a';

		for (int i: range('a','j'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		helpC = 'd';

		for (int i: range('d','d'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		helpC = 'u';

		for (int i: range('u','l'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		helpC = '~';

		for (int i: range('~','*'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		testcase.setname("Chain test");

		help = 0;
		int arr[] = {0,1,2,3,4,5,10,11,12,13,14};
		
		for(int i: chain(range(0,6), range(10,15)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		int arr1[] = {0,1,2,3,4,5,0,1,2,3,4,5};
		
		for(int i: chain(range(0,6), range(0,6)))
		{
			testcase.CHECK_EQUAL(i, arr1[help]);
			help++;				
		}

		help = 0;
		char arrC[] = {'a','b','c','d','e','f','g'};
		
		for(int i: chain(range('a','d'), range('d','h')))
		{
			testcase.CHECK_EQUAL(i, arrC[help]);
			help++;				
		}
		

		help = 0;
		char arrC1[] = {'a','b','c','A','B','C','D'};
		
		for(int i: chain(range('a','d'), range('A','E')))
		{
			testcase.CHECK_EQUAL(i, arrC1[help]);
			help++;				
		}
		// testcase.setname("Play with dummy choosers and guessers")
	
    // .print(cout, /*show_grade=*/false);

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


