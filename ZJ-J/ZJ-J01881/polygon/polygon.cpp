#include<bits/stdc++.h>
using namespace std;
struct flag1{
	string s;
}b[50005];
int xbb=0;
const int mod=998244353;
int ans=0,n,a[50005];
bool flag[50005]={};
void solve(int cnt,int sum,int maxx,bool f[]){
	if(cnt>=3){
		if(maxx*2<sum){
			string c;
			for(int i=1;i<=n;i++){
				if(f[i])c+=to_string(i);
			}
			sort(&c[0],&c[c.size()]);
			bool f1=true;
			for(int i=1;i<=xbb;i++){
				if(c==b[i].s){
					f1=false;
				}
			}
			if(f1){
				xbb++;
				b[xbb].s=c;
				ans++;	
			}
			if(xbb==0){
				xbb++;
				b[xbb].s=c;
				ans++;
			}
		}
		ans%=mod;
		if(cnt==n)return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			solve(cnt+1,sum+a[i],max(maxx,a[i]),f);
			f[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve(0,0,-1e9,flag);
	cout<<ans%mod;
	return 0;
}