#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans,tmp=998244353;
int q[5005],a[5005];
bool vis[5005];
void check(int x){
	int sum=0,maxx=-1,bs=0;
	for(int i=1;i<=x;i++){
		sum+=q[i];
		maxx=max(maxx,q[i]);
	}
	if(2*maxx<sum){
	  ans++;
    }
	ans%=tmp;
}
void dfs(int x,int y){
	if(x==n+1){
		return ;
	}
	for(int i=y;i<=n;i++){
		if(!vis[i]){
			q[x]=a[i];
			vis[i]=1;
			if(x>=3){
				check(x);
			}
			dfs(x+1,i+1);
			vis[i]=0;
			q[x]=0;
		}
	}
}
void solve(int n){
	 ans=-1-n-n*(n-1)/2;
	 int q=1;
	 for(i=1;i<=n;i++){
	 	q*=2;
	 	q=q%tmp;
	 }
	 ans+=q;
	 ans%=tmp;
	 cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    int qq=-1;
    for(i=1;i<=n;i++){
      cin>>a[i];
      qq=max(a[i],qq);
    }
    if(qq==1){
    	solve(n);
	}
	else{
		dfs(1,1);
		cout<<ans;
	}
	return 0;
}

