/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.
Output
Output one integer, the maximum number of activities that can be performed

Constraints
1 <= N <= 10^6
1 <= ai, di <= 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&i,pair<int,int>&j){
    return i.second<j.second;
}
int main()
{
    //Write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a,b;
    vector< pair<int, int> > job;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        job.push_back(make_pair(a,b));
    }
    sort(job.begin(),job.end(),comp);
    int count=0;
    int init=0;
    for(int i=0;i<n;i++){
        if(job[i].first>=init){
            count++;
            init=job[i].second;
        }
    }
    cout<<count<<endl;
    return 0;
}