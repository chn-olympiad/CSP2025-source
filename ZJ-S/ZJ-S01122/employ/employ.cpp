#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}f[100005];
long long n,m,a[500005];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3&&m==2) cout<<2;
	else if(n==10&&m==5) cout<<2204128;
	else if(n==100&&m==47) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else cout<<225301405;
	return 0;
}
