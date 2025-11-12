#include<bits/stdc++.h>
using namespace std;
long long t,n,add,f[100005][5];
bool flag;
struct people{
	long long a,b,c;
}p[100005];
bool cmp(people a,people b){
	return a.a>=b.a;
}
void dfs(long long per,long long c1,long long c2,long long c3,long long add){
	if(c1>=n/2) return ;
	if(c2>=n/2) return ;
	if(c3>=n/2) return ;
	if(per>n+1) return ;
	for(int i=1;i<=3;i++){
		if(i==1){
			if(add+p[per].a<f[per][i]) return ;
			else f[per][i]=add+p[per].a;
		}
		else if(i==2){
			if(add+p[per].b<f[per][i]) return ;
			else f[per][i]=add+p[per].b;
		}
		else{
			if(f[per][i]>add+p[per].c) return ;
			else f[per][i]=add+p[per].c;
		}
	}
	dfs(per+1,c1+1,c2,c3,f[per][1]);
	dfs(per+1,c1,c2+1,c3,f[per][2]);
	dfs(per+1,c1,c2,c3+1,f[per][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		if(n==2){
			long long a,b,c,a1,b1,c1;
			cin>>a>>b>>c>>a1>>b1>>c1;
			add=max(a+b1,a+c1);
			add=max(add,b+a1);
			add=max(add,b+c1);
			add=max(add,c+a1);
			add=max(add,c+b1);
			printf("%lld\n",add);
			add=0;
		}
		else{
			for(int i=1;i<=n;i++){
				scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
				if(p[i].b!=0||p[i].c!=0) flag=true;
			}
			if(flag==false){
				sort(p+1,p+n+1,cmp);
				for(int i=1;i<=n/2;i++) add+=p[i].a;
				printf("%lld\n",add);
				add=0;
			}
			else{
				dfs(1,0,0,0,0);
				long long ma=0;
				for(int i=1;i<=3;i++) ma=max(ma,f[n][i]);
				printf("%lld\n",ma);
			}
		}
	}
	return 0;
}
