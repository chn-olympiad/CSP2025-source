#include<bits/stdc++.h>
using namespace std;
long long a[500100],k,n;
struct rr{
	long long l,r;
};
map<long long,rr>q;
int ans,maxx,aans;
void dfs(long long l,long long r,int sum){
	bool pd=0;
	for(int i=1;i<=ans;i++){
		if(q[i].l>r||q[i].r<l){
			pd=1;
			if(q[i].l>r)dfs(l,q[i].r,sum+1);
			if(q[i].r<l)dfs(q[i].l,r,sum+1);
		}
	}
	if(!pd){
		maxx=max(maxx,sum);
		return;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool A=1;
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		long long b;
		cin>>b;
		if(b>1){
			A=0;
		}
		if(b!=0){
			aans++;
			a[aans]=b;
			a[aans]^=a[aans-1];
		}
	}
	if(A){
		if(k==1)cout<<aans;
		else cout<<aans/2;
		return 0;
	}
	for(int i=1;i<=aans;i++){
		for(int j=i;j<=aans;j++){
			long long nu=a[j]^a[i-1];
			if(nu==k){
				ans++;
				q[ans].l=i;q[ans].r=j;
			}
		}
	}
	for(int i=1;i<=ans;i++){
		dfs(q[i].l,q[i].r,1);
	}
	cout<<maxx;
	return 0;
}
//这道就写了个暴力，感觉有1.4了 
