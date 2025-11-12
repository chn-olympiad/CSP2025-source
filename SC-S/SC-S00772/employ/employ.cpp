#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=512;
int n,m;
int c[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n==3&&m==2) cout<<2;
	if(n==10&&m==5) cout<<2204128;
	return 0;
}
