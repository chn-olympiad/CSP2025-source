#include<bits/stdc++.h>
using namespace std;
const int inff=1e6;
long long t,n,maxx,ans,num;
long long a1[inff],a2[inff],a3[inff];
long long mem1,mem2,mem3;
long long arr[4];
void dfss(long long a1,long long a2,long long a3) {
	arr[1]=a1,arr[2]=a2,arr[3]=a3;
	sort(arr+1,arr+4);
	if(arr[3]==a1&&mem1>0) {
		mem1-=1;
		ans+=arr[3];
	}
	if(arr[3]==a2&&mem2>0) {
		mem2-=1;
		ans+=arr[3];
	}
	if(arr[3]==a3&&mem3>0) {
		mem3-=1;
		ans+=arr[3];
	}
//	cout<<arr[1]<<arr[2]<<arr[3]<<endl;
	return;
}
int main() {
	freopen("club.in","r","std.in");
	freopen("club.out","w","std.out");
	cin>>t;
	for(int time=1; time<=t; time++) {
		ans=0;
		cin>>n;
		num=n/2;
		mem1=num;
		mem2=num;
		mem3=num;
		for(int i=1; i<=n; i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
			dfss(a1[i],a2[i],a3[i]);
		}
		cout<<ans<<endl;
	}

	return 0;
}
