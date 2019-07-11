#include <iostream>
#include <limits>

using namespace std;

// Function to check integer overflow 
bool check_overflow(int num1, int num2)
{
	// Checking if addition will cause overflow 
	if (num1 > INT_MAX - num2)
		return false;

	// No overflow occured 
	else
		return true;
}


int main() {

	char str[] = "34343444443";
	int numb = 0;

	try {

		int size = strlen(str);
		long long int  tmp = 0;
		int counter = 1;

		//check
		for (int i = 0; i < size; i++) {

			if (str[i] < 48 || str[i] > 57) {

				throw 1;
			}
			counter *= 10;
		}

		for (int i = 0; i < size; i++) {
			counter /= 10;
			tmp = (int(str[i]) - 48);
			tmp = tmp * counter;
			
			//Check max int 
			if(check_overflow(numb, tmp)){
				numb += tmp;
			}
			else {
				throw 2;
			}
		}

		cout << numb << endl;
	}
	catch (int a)
	{
		switch (a)
		{
		case 1:
			cout << "Bad int string" << endl;
			break;
		case 2:
			cout << "Max int!" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}