#include<bits/stdc++.h>
using namespace std;
int opp=1,n,ans,a[10005],mmm=998244353;
bool tmp(int a,int b) {
	return a>b;
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	while(opp--){
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,tmp);
		if(a[0]<(a[1]+a[2]))cout<<1;
		else cout<<0;
	}
	return 0;
}
