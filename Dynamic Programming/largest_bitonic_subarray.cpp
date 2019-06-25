/*
You are given an array of positive integers as input. Write a code to return the length of the largest such sub-array in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a sub-array is known as bitonic sub-array. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic sub-array need not be consecutive in the given array but the order should remain same.

Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic Sub-Array
Input Constraints:
1<= N <= 10^5
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic sub-array is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<iostream>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
    int* output = new int[n];
	output[0] = 1;
	for (int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] >= input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
	}
    for(int i=1;i<n;i++){
        for (int j = i - 1; j >= 0; j--) {
			if (input[j] <= input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
    }
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (best < output[i]) {
			best = output[i];
		}
	}
	delete [] output;
	return best;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}