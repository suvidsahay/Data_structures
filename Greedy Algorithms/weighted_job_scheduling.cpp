/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.

Constraints
1 <= N <= 10^6
1 <= ai, di, p <= 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/
#include<bits/stdc++.h>
using namespace std;
struct Job{
	 int st;
	 int end;
	 int profit;
};
bool compare(Job j1 , Job j2){
	  return j1.end<j2.end;
}
int index(Job arr[] , int i){
	   int start = 0;
	   int end = i-1;
	   int j = -1;
	   while(start <= end){
            
	   	     int mid = (start+end)/2;
	   	     if(arr[mid].end == arr[i].st){
                 
	   	     		j = mid;
                
	   	     		start = mid+1;
	   	     		
	   	     }
	   	     if(arr[mid].end > arr[i].st){
	   	     		end = mid-1;
	   	     }
	   	     else{
	   	     	  j = mid;
                 
	   	     	 start = mid+1;
	   	     }
	   	     
	   }
	   return j;
}
int main(){
	  int n;
	  cin >> n;
	  Job arr[n];
	  for(int i = 0 ; i < n ; i++){
	       cin >> arr[i].st >> arr[i].end >> arr[i].profit;
	    }
	    // sort on basis of end time of the job
	    sort(arr , arr + n , compare);
	    // to find maximum profit either by excluding or including 
	      int dp[n];
	      dp[0] = arr[0].profit;
	     for(int i = 1 ; i < n ; i++){
	     	    dp[i] = dp[i-1];
	     	    int j = index(arr  , i);
           //  cout<<j<<endl;
	     	    if(j != -1){
	     	    	  dp[i] = max(dp[i] , dp[j] + arr[i].profit);
	     	    }
	     	    else{
	     	    	  dp[i] = max(dp[i] , arr[i].profit);
	     	    }
	     }
	     cout<<dp[n-1]<<endl;

}