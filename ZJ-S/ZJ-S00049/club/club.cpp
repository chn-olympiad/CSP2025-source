#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int now=0,res=1;char c=getchar();
	while(!isdigit(c))res=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))now=now*10+c-'0',c=getchar();
	return now*res;
}
const int N=1e5+10;
int n,ans,del[N];
pair<int,int>a[N][3];
priority_queue<int>ton[3];
void solve(){
	n=read();ans=0;
	for(int i=0;i<3;i++)while(!ton[i].empty())ton[i].pop();
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			a[i][j]={read(),j};
		sort(a[i],a[i]+3);reverse(a[i],a[i]+3);
		del[i]=a[i][1].first-a[i][0].first;
		ton[a[i][0].second].push(del[i]);
		ans+=a[i][0].first;
	}
	for(int i=0;i<3;i++)
		while(ton[i].size()>n/2)ans+=ton[i].top(),ton[i].pop();
	printf("%lld\n",ans);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=read();
	while(_--)solve();
	return 0;
}

