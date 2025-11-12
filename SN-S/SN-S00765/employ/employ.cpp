#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000008],cnt=1;
string s1;
void f(int x1)
{
	if(x1!=1)
	{
		cnt*=x1;
		f(x1-1);
	}
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	f(n);
	cout<<cnt/m;
	return 0;
}

