#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5e4+3;
int a[N],ans,idx,cnt,maxn,n,x,sum[N],maxn2,maxn3;
bool vis[N];
void dfs(){
	if(idx==x){
		cout<<maxn<<" "<<sum[idx]<<endl;
	    if(sum[idx]>2*maxn){
	   	    ans++;
	   	    ans=ans%MOD;
	    }
	    cout<<ans<<" "<<"12345"<<endl;
	    return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		if(a[i]>maxn){
			maxn3=maxn;
			maxn=a[i];
		}
		vis[i]=true;
		idx++;
		sum[idx]+=a[i]+sum[idx-1];
		dfs();
		sum[idx]=0;
		idx--;
		vis[i]=false;
		maxn=maxn3;
	    }
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	maxn2=-MOD;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn2=max(maxn2,a[i]);
		cnt+=a[i];
	}
	if(n<=2){
		cout<<"0";
		return 0;
	}
	sort(a+1,a+n+1);
	idx=0;
	ans=0;
	for(int i=3;i<n;i++){
		maxn=-MOD;
		maxn2=-MOD;
		maxn3=-MOD;
		memset(vis,false,sizeof(vis));
		memset(sum,0,sizeof(sum));
		x=i;
		idx=0;
		dfs();
	}
	if(cnt>maxn2*2){
		ans++;
		ans=ans%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
