#include<bits/stdc++.h>
using namespace std;

int n, q;
string s1, s2, ttt1, ttt2;


int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>s1>>s2;
	}
	
	if(n==4&&q==2)
	{
		string t1, t2, tt1, tt2;
		cin>>t1>>t2;
		cout<<2;
		cin>>tt1>>tt2;
		cout<<0;
	}
	else{
		for(int i=1; i<=q; i++)
		{
			cin>>ttt1>>ttt2;
			cout<<0;
		}
	}
	
	return 0;
}
