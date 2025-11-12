#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+100;
int n,m;
map<int,int>w;
int a[N];
int top=0,k=0;
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	w[0]=1;
	for(int i=1;i<=n;i++)
	{
		top^=a[i];
		if(w[m^top]==1)
		{
		ans++;
		w.clear();
		k=0;
		w[0]=1;
		top=0;
		}
		else
		{
		    w[top]=1;
		}
	}
	cout<<ans;
	return 0;
}
