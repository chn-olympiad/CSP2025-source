#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=1e5+5;
int n,a[Maxn][5];
int T[5],Cnt;
int Answer;
inline void DFS(int now,int sum) {
	++Cnt;
	if(Cnt>=2e7)
		return;
	if(now==n+1) {
		Answer=max(Answer,sum);
		return;
	}
	for(register int i=1; i<=3; ++i)
		if(T[i]<n/2) {
			++T[i];
			DFS(now+1,sum+a[now][i]);
			T[i]--;
		}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		memset(T,0,sizeof(T));
		Answer=-1;
		Cnt=0;
		cin>>n;
		for(register int i=1; i<=n; ++i)
			for(register int j=1; j<=3; ++j)
				cin>>a[i][j];
		DFS(1,0);
		cout<<Answer<<endl;
	}
	return 0;
}