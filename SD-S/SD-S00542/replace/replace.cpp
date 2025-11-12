#include<bits/stdc++.h>
using namespace std;

const int N=5e6+5;

int n,q;

string s1[N];
string s2[N];

string t1;
string t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while (q--)
	{
		long long ans=0;
		cin>>t1>>t2;
		cout<<ans<<"\n";
	}
	return 0;
}

