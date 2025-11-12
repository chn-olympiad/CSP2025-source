#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005],tot;
bool cmp(int w,int q)
{
	return w>q;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[++tot]=n[i]-'0';
		}
	}
	sort(a+1,a+tot+1,cmp);
	bool e=1;
	for(int i=1;i<=tot;i++)
	{
		if(a[i]!=0) cout<<a[i],e=0;
		else if(e==0) cout<<a[i];
	}
	if(e==1) cout<<0;
	return 0;
}
