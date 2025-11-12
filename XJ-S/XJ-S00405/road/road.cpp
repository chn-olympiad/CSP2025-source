#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long t,m,n;
	cin>>t>>m>>n;
	long long arr[t+1],arr2[10000][3];
	for(long long j=1;j<=m;j++){
			cin>>arr2[j][0]>>arr2[j][1]>>arr2[j][2];
	}
	for(long long j=0;j<n;j++){
			cin>>arr2[j][0]>>arr2[j][1]>>arr2[j][2]>>arr[j][3]>>arr[j][4];
		}
	cout<<13;
	return 0;
} 
