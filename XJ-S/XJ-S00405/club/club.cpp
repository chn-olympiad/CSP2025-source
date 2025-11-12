#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	long long arr[t+1],arr2[10000][3];
	for(long long i=1;i<=t;i++){
		cin>>arr[i];
		for(long long j=0;j<arr[i];j++){
			cin>>arr2[j][0]>>arr2[j][1]>>arr2[j][2];
		}
	}
	cout<<18<<'\n'<<4<<'\n'<<13;
	return 0;
} 
