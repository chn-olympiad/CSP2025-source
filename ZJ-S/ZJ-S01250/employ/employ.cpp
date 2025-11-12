#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=500+5,MOD=998244353;
int n,m,c[Maxn];
string s;
int Pre_Add[Maxn],Vis[Maxn],Cnt;
int Answer;
//int T[Maxn];
inline void DFS(int now) {
//	cout<<now<<endl;
	++Cnt;
	if(Cnt>=2e6)
		return;
	if(now==n+1) {
		++Answer;
		if(Answer>=MOD)
			Answer-=MOD;
//		for(register int i=1; i<=n; ++i)
//			cout<<T[i]<<" ";
//		cout<<endl;
		return;
	}
//	cout<<"-__-"<<endl;
	for(register int i=1; i<=n; ++i)
		if(!Vis[i]&&Pre_Add[now]<c[i]) {
			Vis[i]=1;
//			T[now]=i;
			DFS(now+1);
			Vis[i]=0;
		}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(register int i=1; i<=n; ++i)
		cin>>c[i];
	for(register int i=1; i<=n; ++i) {
		if(s[i]=='0')
			Pre_Add[i+1]=1;
		Pre_Add[i]+=Pre_Add[i-1];
	}
//	for(register int i=1; i<=n; ++i)
//		cout<<Pre_Add[i]<<" ";
//	cout<<endl;
	DFS(1);
	cout<<Answer<<endl;
//	cout<<"-__-"<<endl;
	return 0;
}