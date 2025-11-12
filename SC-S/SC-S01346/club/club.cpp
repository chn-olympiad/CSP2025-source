#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[10000005];
int brr[10000005];
int crr[10000005];
int trr[105];
int main(int argc, char** argv) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	long long n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>arr[j]>>brr[j]>>crr[j];
		}
		for(int j=0;j<n;j++){
			if(arr[j]<brr[j]){
				trr[t]=trr[t]+max(brr[j],crr[j]);
			}
			else{
				trr[t]=trr[t]+max(arr[j],crr[j]);
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<trr[i]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}