// The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.
#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int sum1=0,sum2=0;
	vector<int> v;
	for(int i=0;i<n;i++){
		sum1=sum1*10;
		sum1=sum1+a[i];
	}
	for(int i=0;i<m;i++){
		sum2=sum2*10;
		sum2=sum2+b[i];
	}
	int sum = sum1 + sum2;
	while(sum){
			v.push_back(sum%10);
			sum/=10;
		}
	reverse(v.begin(),v.end());
	return v;
	
}