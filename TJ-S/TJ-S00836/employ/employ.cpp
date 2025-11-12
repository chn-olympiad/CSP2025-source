#include<bits/stdc++.h>
using namespace std;
int n,m,c[10000005];
string s1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	cout<<m%n; 
	return 0; 
}

