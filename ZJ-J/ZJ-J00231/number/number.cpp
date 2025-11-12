#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=1000010;
ll n,a[N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char op:s)
	{
		if(op>='0'&&op<='9')
		{
			a[++n]=op-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}