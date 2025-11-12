#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt,mod=998244353;
int f(vector<int> p,int no)
{
	unsigned long long t = 0;
	if(no==n+1)
	{
		for(int i = 0;i < p.size();i++) t+=p[i];
		if((!p.empty()) && t>p[p.size()-1]*2) return 1;
		return 0;
	}
	t+=f(p,no+1)%mod;
	p.push_back(a[no]);
	t+=f(p,no+1)%mod;
	return t%mod;
}
vector<int> p;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << f(p,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
