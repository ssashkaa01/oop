#include <iostream>
#include <limits>


using namespace std;
// Function to check integer overflow 
int check_overflow(int num1, int num2)
{
	// Checking if addition will cause overflow 
	if (num1 > INT_MAX - num2)
		return -1;

	// No overflow occured 
	else
		return num1 + num2;
}


int main() {

	char str[] = "23323343443432";
	int numb = 0;

	try {

		int size = strlen(str);
		long long int  tmp = 0;
		int counter = 1;

		//check
		for (int i = 0; i < size; i++) {

			if (str[i] < 48 || str[i] > 57) {

				//if(str[0])
				throw 1;
			}
			counter *= 10;
		}

		for (int i = 0; i < size; i++) {
			counter /= 10;
			tmp = (int(str[i]) - 48);
			tmp = tmp * counter;
			
			if(true){
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