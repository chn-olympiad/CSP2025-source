#include<bits/stdc++.h>
using namespace std;
int t,n,m[100050][5];
long long ans;
void f(int i,int a,int b,int c,long long s){
	if(i>n){
		ans=max(ans,s);
		return;
	}
	if(a<n/2)
		f(i+1,a+1,b,c,s+m[i][1]);
	if(b<n/2)
		f(i+1,a,b+1,c,s+m[i][2]);
	if(c<n/2)
		f(i+1,a,b,c+1,s+m[i][3]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&m[i][1],&m[i][2],&m[i][3]);
		f(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
