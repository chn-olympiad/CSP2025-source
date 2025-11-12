#include<bits/stdc++.h>
using namespace std;
string aa;
long long vis[100100],x[100100],arr[100100],ans=0,n,m;
int check(){
	long long pre=0,t=0;
	for(int i=0;i<n;i++){
		if(aa[i]=='1'&&pre<arr[x[i+1]]) {
			t++;
		}
		else pre++;
	}
	if(t>=m) return 1;
	else return 0;
}
void dfs(long long step){
	if(step==n+1){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			x[step]=i;
			vis[i]=1;
			dfs(step+1);
			x[step]=0;
			vis[i]=0;
		}
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>aa;
	if(n==m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;//这就是我和dfs热血沸腾的组合技啊啊啊啊啊啊啊啊啊啊啊 看我不卡爆你测评机！！！ 
	//不豪我似乎想到了dp方程！！！但是tmd时间来不及了
	//如果这道题真是tmd用dp做的记得谁看见了来锤我luoguuid566190我是歌者啊啊啊啊啊啊
	 
}
