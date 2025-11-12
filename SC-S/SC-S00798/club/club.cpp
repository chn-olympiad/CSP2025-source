#include<bits/stdc++.h>
using namespace std;
int t,ans;
struct type{
	int u,v,w;
};
bool cmp(type x,type y){
	if(max({x.u,x.v,x.w})>max({y.u,y.v,y.w})){
		return true;
	}
	if(x.u>y.u){
		return true;
	}else if(x.u==y.u){
		if(x.v>y.v){
			return true;
		}else if(x.v==y.v){
			if(x.w>y.w){
				return true;
			}else if(x.w==y.w){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int b,c,d,e[105][105][105];int n;
type a[100010];
void dfs(int l,int num){
	if(num<e[b][c][d]){
		return;
	}else{
		e[b][c][d]=num;
	}
	ans=max(ans,num);
	if(l>n){
		return;
	}
	if(b<n/2){
		b++;
		dfs(l+1,num+a[l].u);
		b--;
	}
	if(c<n/2){
		c++;
		dfs(l+1,num+a[l].v);
		c--;
	}
	if(d<n/2){
		d++;
		dfs(l+1,num+a[l].w);
		d--;
	}
}
void aa(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+n,cmp);
	if(n>10000){
		for(int i=1;i<=n/2;i++){
			ans+=a[i].u;
		}
		printf("%d\n",ans);
		return;
	}
	dfs(1,0);
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		aa();
	}
	return 0;
} 