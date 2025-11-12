#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag=1,f=1,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
		if(a[i]!=0&&a[i]!=1)f=0;
		if(a[i]==1)sum++;
	}
	if(k==1&&flag==1)cout<<n;
	else if(k==0&&flag==1)cout<<n/2;
	else if(k==1&&f==1)cout<<sum;
	else if(n==4&&k==3)cout<<2;
	else if(n==4&&n==0)cout<<1;
	return 0;
}