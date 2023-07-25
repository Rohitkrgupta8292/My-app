#include <iostream>
using namespace std;

int main()
{
	// declaration of variables.
	int input[] = {25,11,7,75,56}, min = input[0],size = sizeof(input) / sizeof(input[0]);

    // iterating till the last index.  
	for(int i = 1; i < size; i++)
	{
        // checking first index from loop i.
		if(input[i] < min)
	    {
            // Update the smallest number if a smaller one is found
	    	min = input[i];
	    }
	}
    // printing the smallest number from given array.
	cout<<"The smallest number in the array is:"<<min<<endl;
	
    return 0;
}