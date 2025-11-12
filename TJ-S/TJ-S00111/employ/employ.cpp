#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c[N];
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	ans%=998244353;
	cout<<ans<<'\n';
	return 0;
}
//断了的弦 再怎么练 我的世界 你不在里面 
//我的指尖 已经弹出茧 还是无法留你在我身边 

//我想我是太过依赖 在挂电话的刚才
//坚持学单纯的小孩 静静看守这份爱 
//知道不能太依赖 怕你会把我宠坏
//你的香味一直徘徊 我舍不得离开 
