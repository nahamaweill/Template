#include <iostream>
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
using namespace std;
using namespace itertools;

int main()
{
	badkan::TestCase testcase;
	int grade = 0; //Inits the grade.
	int signal = setjmp(badkan::longjmp_buffer);
	if(signal == 0)
	{

		//---------------------Range test---------------------

		testcase.setname("Range test:");

		//Checks if the range is between 0-34:
		int help = 0;
		for (int i: range(0, 35))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		//Checks if the range is between 5-6:
		help = 5;
		for (int i: range(5, 7))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		//Checks if the range is between (-10)-(-9):
		help = -10;
		for (int i: range(-10, 0))
		{
			testcase.CHECK_EQUAL(i, help);
			help++;
		}

		//Checks if the range is 101:
		help = 101;
		for (int i: range(101, 102))
		{
			testcase.CHECK_EQUAL(i, help);
		}

		//Checks if the range is 2:
		help = 2;
		for (int i: range(2, 2))
		{
			testcase.CHECK_EQUAL(i, help);
		}

		//Checks if the range is between a-i:
		char helpC = 'a';
		for (char i: range('a', 'j'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		//Checks if the range is d:
		helpC = 'd';
		for (char i: range('d', 'd'))
		{
			testcase.CHECK_EQUAL(i, helpC);
		}

		//Checks if the range is between u-k:
		helpC = 'u';
		for (char i: range('u', 'l'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		//Checks if the range is between ~-):
		helpC = '~';
		for (char i: range('~', '*'))
		{
			testcase.CHECK_EQUAL(i, helpC);
			helpC++;
		}

		//---------------------Chain test---------------------

		testcase.setname("Chain test:");

		help = 0;
		int arr[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14};
		for(auto i: chain(range(0, 6), range(10, 15)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		int arr1[] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
		for(auto i: chain(range(0, 6), range(0, 6)))
		{
			testcase.CHECK_EQUAL(i, arr1[help]);
			help++;				
		}

		help = 0;
		char arrC[] = {'a', 'b', 'c', 'e', 'f', 'g'};
		for(auto i: chain(range('a', 'd'), range('e', 'h')))
		{
			testcase.CHECK_EQUAL(i, arrC[help]);
			help++;				
		}

		help = 0;
		char arrC[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
		for(auto i: chain(range('a', 'd'), range('d', 'h')))
		{
			testcase.CHECK_EQUAL(i, arrC[help]);
			help++;				
		}
		
		help = 0;
		char arrC1[] = {'a', 'b', 'c', 'A', 'B', 'C', 'D'};
		for(auto i: chain(range('a', 'd'), range('A', 'E')))
		{
			testcase.CHECK_EQUAL(i, arrC1[help]);
			help++;				
		}

		help = 0;
		char arrC1[] = {'a', 'b', 'c', 'h', 'e', 'l', 'l', 'o'};
		for(auto i: chain(range('a', 'd'), string("hello")))
		{
			testcase.CHECK_EQUAL(i, arrC1[help]);
			help++;				
		}

		//---------------------Zip test---------------------

		testcase.setname("Zip test:");

		help = 0;
		string arr[] = {"1, h", "2, e", "3, l", "4, l", "5, o"};
		for(auto i: zip(range(1, 6), string("hello")))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"1, 1", "2, 2", "3, 3", "4, 4", "5, 5"};
		for(auto i: zip(range(1, 6), range(1, 6)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"1, 6", "2, 7", "3, 8", "4, 9", "5, 10"};
		for(auto i: zip(range(1, 6), range(6, 11)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"e, t", "x, e", "a, s", "m, t", "p, i", "l, n", "e, g"};
		for(auto i: zip(string("example"), string("testing")))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		int arrCheck[] = {1, 2, 3};
		string arr[] = {"h, 1", "e, 2", "y, 3"};
		for(auto i: zip(string("hey"), arrCheck))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		//---------------------Product test---------------------

		testcase.setname("Product test:");

		help = 0;
		string arr[] = {"1,h", "1,e", "1,l", "1,l", "1,o",
		                "2,h", "2,e", "2,l", "2,l", "2,o",
		                "3,h", "3,e", "3,l", "3,l", "3,o",
										"4,h", "4,e", "4,l", "4,l", "4,o",
										"5,h", "5,e", "5,l", "5,l", "5,o"};
		for(auto i: product(range(1, 6), string("hello")))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"1,1", "1,2",
		                "2,1", "2,2"};
		for(auto i: product(range(1, 3), range(1, 3)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"1,4", "1,5", "1,6", "1,7", "1,8", "1,9",
		                "2,4", "2,5", "2,6", "2,7", "2,8", "2,9",
										"3,4", "3,5", "3,6", "3,7", "3,8", "3,9"};
		for(auto i: product(range(1, 4), range(4, 10)))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		string arr[] = {"e,t", "e,e", "e,s", "e,t", "e,i", "e,n", "e,g",
		                "x,t", "x,e", "x,s", "x,t", "x,i", "x,n", "x,g",
										"a,t", "a,e", "a,s", "a,t", "a,i", "a,n", "a,g",
										"m,t", "m,e", "m,s", "m,t", "m,i", "m,n", "m,g",
										"p,t", "p,e", "p,s", "p,t", "p,i", "p,n", "p,g",
										"l,t", "l,e", "l,s", "l,t", "l,i", "l,n", "l,g",
										"e,t", "e,e", "e,s", "e,t", "e,i", "e,n", "e,g"};
		for(auto i: product(string("example"), string("testing")))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		help = 0;
		int arrCheck[] = {1, 2, 3};
		string arr[] = {"h,1", "h,2", "h,3",
		                "e,1", "e,2", "e,3",
										"y,1", "y,2", "y,3"};
		for(auto i: product(string("hey"), arrCheck))
		{
			testcase.CHECK_EQUAL(i, arr[help]);
			help++;				
		}

		//---------------------Powerset test---------------------

		testcase.setname("Powerset test:");

		string ans[] = {"{}", "{a}", "{b}", "{a,b}", "{c}", "{a,c}", "{b,c}", "{a,b,c}"};
		for (auto i: powerset(string("abc")))
		{
			testcase.CHECK_EQUAL(i, ans[i]);
			i++;
		}

		string ans[] = {"{}", "{1}", "{2}", "{1,2}"};
		for (auto i: powerset(range(1,3)))
		{
			testcase.CHECK_EQUAL(i, ans[i]);
			i++;
		}

		int check[] = {1, 2}
		string ans[] = {"{}", "{1}", "{2}", "{1,2}"};
		for (auto i: powerset(check))
		{
			testcase.CHECK_EQUAL(i, ans[i]);
			i++;
		}

		//------------------------------------------------------

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


