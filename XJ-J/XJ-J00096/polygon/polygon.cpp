#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,k,t;
	cin>>n;
	int Max=-1,cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		cnt+=t;
		Max=max(Max,t);
	} 
	Max*=2;
	cout<<Max<<' '<<cnt<<endl;
	if(cnt>Max) cout<<1;
	else cout<<0;
	return 0;
}
