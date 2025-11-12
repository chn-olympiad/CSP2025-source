#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353; 

int n;
long long ans=0;
int a[5050];
bool vis[5050];

//       刚才选了谁  选了多少数 总和  最大   要选多少 
void dfs(int step,int cnt,long long sum,int mx,int k){
	
	if(cnt==k){
		
		if(sum>mx*2){
			ans++;
		}
		
	}	
	
	for(int i=step+1;i<=n;i++){
		
		if(!vis[i]){
			
			vis[i]=1;
			dfs(i,cnt+1,sum+a[i],max(mx,a[i]),k);
			vis[i]=0;
			
		} 
		
	}
	
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	long long anc=0;
	for(int i=3;i<=n;i++){
		
		memset(vis,0,sizeof(vis));
		dfs(0,0,0,0,i);
		anc=(anc+ans)%Mod;
		ans=0;
		
	}
	
	cout<<anc%Mod;
	//wc了T4还能写个暴力 T3暴力都写不出来 我活着干啥找个楼跳了吧 
	//密密麻麻是我的自尊 
	return 0;
	
}
