#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct qqqqq{
	long long a,b,c;
};
bool cmp(qqqqq s,qqqqq t){return s.a>t.a;}
qqqqq l[N];
int n;
long long ans=0;
inline void dfs(int f,int s,int tt,int t,long long res){
	if(t==n){ans=max(res,ans);return;}
	if(f<n/2)dfs(f+1,s,tt,t+1,res+l[t].a);
	if(s<n/2)dfs(f,s+1,tt,t+1,res+l[t].b);
	if(tt<n/2)dfs(f,s,tt+1,t+1,res+l[t].c);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(register int i=0;i<n;i++){
			scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
		}
		bool f1=1;
		for(register int i=0;i<n;i++){
			if(l[i].b!=0 || l[i].c!=0){f1=0;break;}
		}
		if(f1){
			sort(l,l+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=l[i].a;
			}
		}else dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

