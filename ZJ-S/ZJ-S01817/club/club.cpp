#include<bits/stdc++.h>
using namespace std;
struct abc{
	int a;
	int b;
	int c;
	int u;
};
abc x[100010];
bool cmp(abc y,abc z){
	return y.u<z.u;
}
int n;
int aa,bb,cc;
long long sh;
long long h;
void dfs(int d){
	if(d>n){
		if(aa<=n/2&&bb<=n/2&&cc<=n/2){
			h=max(h,sh);
		}
		return ;
	}
	if(aa<=n/2){
		aa++;
		sh+=x[d].a;
		dfs(d+1);
		sh-=x[d].a;
		aa--;
	}
	if(bb<=n/2){
		bb++;
		sh+=x[d].b;
		dfs(d+1);
		sh-=x[d].b;
		bb--;
	}
	if(cc<=n/2){
		cc++;
		sh+=x[d].c;
		dfs(d+1);
		sh-=x[d].c;
		cc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		if(n<=30){
			dfs(1);
			cout<<h<<endl;
			sh=0;
			h=0;
		}else{
			for(int i=1;i<=n;i++){
				x[i].u=x[i].a-x[i].b;
			}
			sort(x+1,x+n+1,cmp);
			long long s=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					s+=x[i].b;
				}else if(i>(n+1)/2){
					s+=x[i].a;
				}else{
					s+=max(x[i].a,x[i].b);
				}
			}
			cout<<s<<endl;
		}
	}
	
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/