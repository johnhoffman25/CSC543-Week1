//John Hoffman - F00555643
//CSC 543
//Assignment 1 - Indicies
//09/05/2021

#include<iostream>
using namespace std;

int main(){

    //Constraints:
    //2 <= numList.length <= 104
    //-109 <= numList[i] <= 109
    //-109 <= target <= 109

    //Initializing a few different arrays for testing purposes

    int numList[4] = {2,7,11,15};
    //int numList[3] = {3,2,4};
    //int numList[2] = {3,3};

    //Input the target value
    int target = 9;

    //Get the length of the array we are using
    int arrayLength = sizeof(numList)/sizeof(numList[0]);

    //Loop through the list, checking each index value against every other value to find a pair that will total up to our target value
    for (int i = 0; i < arrayLength; i++) {
        for (int j = 1; j < arrayLength; j++) {
            if (numList[i] + numList[j] == target && i != j) {
                cout << "Target of (" << target << ") found" << "\n";
                cout << "Index: " << i << " and Index: " << j << "\n";
                cout << "Value: " << numList[i] << " and Value: " << numList[j] << "\n";
                cout << numList[i] << " + " << numList[j] << " = " << target;

                //We can assume that there is only one solution, so if there is a solution found, we can quit the program
                return 0;
            }
            else {
                j++;
            }
        }
    }

    //Display an error message if the target value could not be reached
    cout << "Sorry, there are no two numbers in the array provided that add up to the target number";

    return 0;
}