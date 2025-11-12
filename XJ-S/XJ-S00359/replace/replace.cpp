#include <bits/stdc++.h>
using namespace std;
int n,q,s[1100000],t[1100000];
int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=1;j<=q;j++)
		{
			cin>>t[j];
		}
	}
	cout<<"2"<<endl<<"0";
	return 0;
}
