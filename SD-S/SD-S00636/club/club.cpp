#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+1;
int t,n,cnt[4],a[N][4],ans;
int mx[N],s[N];
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(sum+(s[n]-s[x-1])<=ans) return ;
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mx[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			s[i]=s[i-1]+mx[i];
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
//曾经受过一些伤害 曾经有些看不开 却也担心迎接将来 怕爱再卷来 所以我已停止爱 倒也过得挺自在 我的爱 停泊在 无风的海 
//有点奇怪 天使带你来 叫我期待重新振作起来 别让自己后悔 把眼泪收回 不跟谁斗苦斗累 感谢你的出现 过去的往事就如烟 在眼前什么都不欠 你是下雨时的屋檐 那份爱没时限幸福就在我们之间 感动的模糊了视线 那憧憬的一转眼一瞬间就能实现 在有生之年
// my only girlfriend.  my only girlfriend
// 曾经有过一些时候 以为所谓的自由 是每个路口往后只有我一个人走 曾经我以为成熟 是寂寞能够承受 收紧了 孤独的 那一双手 
