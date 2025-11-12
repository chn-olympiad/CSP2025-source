#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],M,cnt;
void DFS(int x,int u)
{
	if(x>n)
	{
		cnt=max(cnt,u);
		return ;
	}
	else
	{
		int e=0;
		bool p=false;
		for(int i=x;i<=n;i++)
		{
			e^=a[i];
			if(e==k)
			{
				p=true;
				DFS(i+1,u+1);
			}
		}
		if(!p) DFS(x+1,u);
		return ;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		M=max(M,a[i]);
	}
	if(M<k)
	cout<<0<<endl;
	else
	{
		DFS(1,0);
		cout<<cnt<<endl;
	}
	return 0;
}
