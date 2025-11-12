#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	int sum=0,cnt=0,count=0;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		sum+=(a[i-1]+4+0+0);
		cnt+=(0+0+a[i]*2-5+3)/2;
		count+=0+0+a[i]+2;
	}
	cout<<sum<<'\n'<<cnt<<'\n'<<count;
	return 0;
} 
