//此题预计能拿到60
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int t,n,ans;
int a[maxn][4],jl[4],s[maxn],c[maxn];
inline bool cmp(int x,int y){
	return x>y;
}
inline void dfs(int x,int sum){
	if(x>n){
		ans = max(ans,sum);
		return ;
	}
	for(int i = 1;i<=3;++i){
		if(jl[i]<n/2){
			jl[i]++;
			if(sum+s[x]>ans)
				dfs(x+1,sum+a[x][i]);
			jl[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	ans = 0;
	while(t--){
		cin>>n;
		memset(c,0,sizeof(c));
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=3;++j){
				cin>>a[i][j];
				c[i] = max(c[i],a[i][j]);
			}
		}
		bool mao=0;
		for(int i = 1;i<=n;++i){
			if(a[i][2]!=0||a[i][3]!=0){
				mao = 1;
				break;
			}
		}
		ans = 0;
		if(!mao){
			for(int i = 1;i<=n;i++)
				c[i] = a[i][1];
			sort(c+1,c+n+1,cmp);
			for(int i = n;i>=n/2;i--)
				ans+=c[i];
			cout<<ans<<'\n';
			continue;
		}
		mao = 0;
		for(int i = 1;i<=n;i++){
			if(a[i][3]!=0){
				mao = 1;
				break;
			}
		}
		if(!mao){
			for(int i = 1;i<=n;i++)
				ans+=a[i][1];
			for(int i = 1;i<=n;i++)
				c[i] = a[i][2]-a[i][1];
			sort(c+1,c+n+1,cmp);
			for(int i = 1;i<=n/2;i++)
				ans+=c[i];
			cout<<ans<<'\n';
			continue;
		}
		for(int i = n;i>=1;--i)
			s[i] = s[i+1]+c[i];
		
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
//只能拿到20分，剪枝以后可以有40分不过很繁琐 
//其实不然，今天被幸运女神眷顾了，剪了一个点就有40了
//那么。。。接下来呢我似乎已经被逼入绝境了
//一个小时了还是只有四十分啊。。。但那又何妨
//没人能比我更懂骗分 
//呵呵，两个小时了就只能再加上5分，草（一种植物） 
//突然间出现了一种新的思路
//假定所有人一开始都在同一个部门
//剩下的就是转单位了
//让我先拿B组特殊数据试试水 
//完美的拿到了B组的分数
//于是乎我现在这道题能砍下来60分了
//我真nb 
//愿伟大而又万能的爱丽丝神保佑我rp++ 