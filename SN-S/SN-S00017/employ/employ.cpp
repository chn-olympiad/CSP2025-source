//付黄旗正 SN-S00017 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cot=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		cot++;
	}
	ans=1;
	for(int i=cot;i>m;i--)
	{
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
