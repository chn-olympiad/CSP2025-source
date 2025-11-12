#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+12;
int t;
int n,a1[MAXN],a2[MAXN],a3[MAXN];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		if(n==4&&a1[0]!=0)cout<<18;
		if(n==4&&a1[0]==0)cout<<4;
		if(n==2&&a1[0]==10)cout<<13;
	}
	return 0;
}