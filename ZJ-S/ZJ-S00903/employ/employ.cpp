#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,t=0,x;
ll ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) {cin>>x;if(x==0) t+=1;}
	for(int i=n;i>t;i--) {ans*=n;ans%=998224353;}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
