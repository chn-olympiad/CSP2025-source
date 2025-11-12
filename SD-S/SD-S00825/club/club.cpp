#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,cys;
vector<int> v1,v2,v3;
struct node{
	int a,b,c,d1d,d2d,d3d;
}stud[110000];
bool cmp(node x,node y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;
		}
		return x.b>y.b;
	}
	return x.a>y.a;
}
void dfs(int x,int yi,int er,int san,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
	if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
	if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
	
}
void dfs1(int x,int yi,int er,int san,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(stud[x].d1d==1){
		if(stud[x].d2d==2){
			if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
			else if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
			else if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
		}else{
			if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
			else if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
			else if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
			
		}
		
	}else if(stud[x].d1d==2){
		if(stud[x].d2d==1){
			if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
			else if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
			else if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
		}else{
			if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
			else if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
			else if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
			
		}
		
	}else{
		if(stud[x].d2d==1){
			if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
			else if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
			else if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
		}else{
			if(san<cys)dfs(x+1,yi,er,san+1,sum+stud[x].c);
			else if(er<cys)dfs(x+1,yi,er+1,san,sum+stud[x].b);
			else if(yi<cys)dfs(x+1,yi+1,er,san,sum+stud[x].a);
		}		
	}		
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		int cis0=1,bis0=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&stud[i].a,&stud[i].b,&stud[i].c);
			if(stud[i].a>stud[i].b&&stud[i].a>stud[i].c){
				stud[i].d1d=1;
				if(stud[i].b>stud[i].c) stud[i].d2d=2,stud[i].d3d=3;
				else stud[i].d2d=3,stud[i].d3d=2;
			}else if(stud[i].b>stud[i].a&&stud[i].b>stud[i].c){
				stud[i].d1d=2;
				if(stud[i].a>stud[i].c) stud[i].d2d=1,stud[i].d3d=3;
				else stud[i].d2d=3,stud[i].d3d=1;
			}else{
				stud[i].d1d=3;
				if(stud[i].a>stud[i].b) stud[i].d2d=1,stud[i].d3d=2;
				else stud[i].d2d=2,stud[i].d3d=1;
			}
			if(stud[i].c!=0) cis0=0;
			if(stud[i].b!=0) bis0=0;
		}
		cys=n/2;
		if(cis0==1&&bis0==1){
			sort(stud+1,stud+1+n,cmp);
			for(int i=1;i<=cys;i++){
				ans+=stud[i].a;
			}
			printf("%lld\n",ans);
		}else if(n<=10){
			//sort(stud+1,stud+1+n,cmp);
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
		}else{
			dfs1(1,0,0,0,0);
		}
	}
	return 0;
}
