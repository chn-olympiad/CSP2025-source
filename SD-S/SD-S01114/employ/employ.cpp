#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[100];
int vis[100];
int p[100];
void dfs(int now) {
	if(now>n) {
		int cnt=0,num=0;
		for(int i=1; i<=n; i++) {
			if(s[i]=='0') {
				num++;
				continue;
			}
			if(num>=c[p[i]]) {
				num++;
				continue;
			}
			cnt++;
		}
		ans+=(cnt>=m);
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i])
			continue;
		p[now]=i;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(n<=18) {
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
//第一次参加CSP-S，现在已经绝望了
//期望得分：|_100'_|+|_20'_|+|_10'_|+|_8'_|=|_138'_|应该能二等吧
//希望期望得分是对的
//上午考J组的时候离结束还有10分钟时发现T2的O(1)的结论写错了
//改完刚测完样例就结束了，没自己对拍 ，希望后来改对了
//上善若水，人杰地灵
//不是，考试还能玩浏览器的断网games？这哥们牛逼 
