#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int Mod = 998244353;

int n;
int a[N];
int ans;
int f[N];
int f_i=0;

void dfs(int l,int total)
{	
	if(l>n) return;
	for(int i = l;i<=n;i++)
	{
		f[++f_i]=a[i];
		dfs(i+1,total+f[f_i]);
		total+=f[f_i];
		if(total>f[f_i]*2) 
		{	
			ans=(ans+1)%Mod;
		}
		total-=f[f_i];
		f_i--;
	}	
}


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout << ans;
	
	return 0;
}
