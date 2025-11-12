#include<bits/stdc++.h>
//#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	x=ch^48;
	ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int t,n;
const int maxn=1e5+5;
struct people{
	pair<int,int> m[3];
	int ch,sx,cx;
}a[maxn];
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].m[0].first=read();
		a[i].m[1].first=read();
		a[i].m[2].first=read();
		a[i].m[0].second=0;
		a[i].m[1].second=1;
		a[i].m[2].second=2;
		sort(a[i].m,a[i].m+3);
		a[i].ch=a[i].m[2].first-a[i].m[1].first;
		a[i].sx=a[i].m[2].second;
		a[i].cx=a[i].m[1].second;
	}
	set<pair<int,int> > mp[3];
	for(int i=1;i<=n;i++){
		int sx=a[i].sx;
		int cx=a[i].cx;
		int ch=a[i].ch;
		if(mp[sx].size()<n/2)mp[sx].insert({ch,i});
		else{
			auto p=*(mp[sx].begin());
			int id=p.second;
			if(p.first<ch){
				mp[sx].erase(mp[sx].begin());
				mp[sx].insert({ch,i});
				mp[a[id].cx].insert({a[id].ch,id});
			}else{
				mp[cx].insert({0x3f3f3f3f,i});
			}
		}
	}
	int ans=0;
	for(int i=0;i<=2;i++){
		for(auto it:mp[i]){
			int id=it.second;
			if(i==a[id].sx)ans+=a[id].m[2].first;
			else ans+=a[id].m[1].first;
		}
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)solve();
	return 0;
}
