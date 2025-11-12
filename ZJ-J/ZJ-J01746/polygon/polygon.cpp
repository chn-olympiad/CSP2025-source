#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll ret=0;
int n;
vector<int> a;
bool vis[5010];
void dfs(int k,int sum,int maxx,int now){
	//cout<<k<<endl;
	if(k==0){
		if(sum>2*maxx) ret=(ret+1)%mod;
		return ;
	}
	for(int i=now+1;i<n;i++){
		if(!vis[i]){
			int temp=maxx;
			vis[i]=true;
			sum+=a[i];
			maxx=max(maxx,a[i]);
			dfs(k-1,sum,maxx,i);
			sum-=a[i];
			maxx=temp;
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		if(x!=1) flag=false;
	}
	if(n<=3){
		sort(a.begin(),a.end());
		if(a[0]+a[1]>a[2]) cout<<1;
		else cout<<0;
	}else if(flag){
		for(int len=3;len<=n;len++){
			ll cnt=1,k=n;
			for(int i=0;i<len;i++,k--) cnt=(cnt*k)%mod;
			k=len;
			while(k){
				cnt=(cnt/k)%mod;
				k--;
			}
			ret=(ret+cnt)%mod;
		}
		cout<<ret;
	}else{
		for(int len=3;len<=n;len++){
			fill(vis,vis+n+1,false);
			dfs(len,0,0,-1);
		}
		cout<<ret;
	}
	return 0;
}
