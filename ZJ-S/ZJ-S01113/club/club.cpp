#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,X=110;
int T, n;
int ans;
struct node{
	int a,b,c;
}x[N];
int f[2][X][X][X];
bool cmpa(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	return x.b>y.b;
}
bool cmpb(node x,node y){
	if(x.b!=y.b)return x.b>y.b;
	return x.a>y.a;
}
bool cmpc(node x,node y){
	return x.c>y.c;
}
void dfs(int step,int a,int b,int c,int sum){
	if(step>n){
		ans=max(ans,sum);
		return ;
	}
	if(a+1<=n/2) dfs(step+1,a+1,b,c,sum+x[step].a);
	if(b+1<=n/2) dfs(step+1,a,b+1,c,sum+x[step].b);
	if(c+1<=n/2) dfs(step+1,a,b,c+1,sum+x[step].c);
}

void calc(){
	memset(f,0,sizeof(f));
	bool fA=0,fB=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(x[i].b)fA=1;
		if(x[i].c)fB=1;
	}
//	if(n<=10){
//		dfs(1,0,0,0,0);
//		cout<<ans<<endl;
//	}
//	else 
	if(n<=200){
		f[0][0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int x1=0;x1<=min(i-1,n/2);x1++){
				for(int x2=0;x2<=min(i-1-x1,n/2);x2++){
					int now=i%2,last=(i+1)%2;
					int x3=i-1-x1-x2;
					if(x3>n/2)continue;
					if(x1+1<=n/2)
					f[now][x1+1][x2][x3]=max(f[last][x1][x2][x3]+x[i].a,f[now][x1+1][x2][x3]);
					if(x2+1<=n/2)
					f[now][x1][x2+1][x3]=max(f[last][x1][x2][x3]+x[i].b,f[now][x1][x2+1][x3]);
					if(x3+1<=n/2)
					f[now][x1][x2][x3+1]=max(f[last][x1][x2][x3]+x[i].c,f[now][x1][x2][x3+1]);
				}
			}
		}
		for(int x1=0;x1<=n/2;x1++){
			for(int x2=0;x2<=min(n-x1,n/2);x2++){
				int x3=n-x1-x2;
				if(x3>n/2)continue;
				ans=max(f[n%2][x1][x2][x3],ans);
			}
		}
		cout<<ans<<endl;
	}
	else if(fA&&fB){
		sort(x+1,x+1+n,cmpa);
		for(int i=1;i<=n/2;i++){
			ans+=x[i].a;
		}
		cout<<ans<<endl;
	}
	else if(fB){
//		int f2[2][N/2]={};
//		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int x1=0;x1<=min(i-1,n/2);x1++){
				for(int x2=0;x2<=min(i-1-x1,n/2);x2++){
					int now=i%2,last=(i+1)%2;
					int x3=i-1-x1-x2;
					if(x3>n/2)continue;
					if(x1+1<=n/2)
					f[now][x1+1][x2][x3]=max(f[last][x1][x2][x3]+x[i].a,f[now][x1+1][x2][x3]);
					if(x2+1<=n/2)
					f[now][x1][x2+1][x3]=max(f[last][x1][x2][x3]+x[i].b,f[now][x1][x2+1][x3]);
					if(x3+1<=n/2)
					f[now][x1][x2][x3+1]=max(f[last][x1][x2][x3]+x[i].c,f[now][x1][x2][x3+1]);
				}
			}
		}
		for(int x1=0;x1<=n/2;x1++){
			for(int x2=0;x2<=min(n-x1,n/2);x2++){
				int x3=n-x1-x2;
				if(x3>n/2)continue;
				ans=max(f[n%2][x1][x2][x3],ans);
			}
		}
		cout<<ans<<endl;
	}
	else{
	}
}

signed main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		calc();
	}
	return 0;
}
