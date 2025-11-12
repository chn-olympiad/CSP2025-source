#include<bits/stdc++.h>
using namespace std;
string s;
int c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	for(int i=n;i>0;i++) ans=(ans*i)%998244353;
	printf("%d",ans);
	return 0;
}
