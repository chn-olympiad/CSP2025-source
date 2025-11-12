#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+3,INF=0x3f3f3f3f3f3f3f3f;
inline ll read(){
	ll x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll n,ans,b[4];
vector<int> p[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		n=read(),ans=0ll;
		b[1]=b[2]=b[3]=0ll;
		for(int i=1;i<=3;i++){
			p[i].clear();
		}
		for(int i=1;i<=n;i++){
			vector<pair<int,int> > a;
			for(int j=1;j<=3;j++){
				a.push_back({read(),j});
			}
			sort(a.begin(),a.end());
			ans+=a[2].first;
			b[a[2].second]++;
			p[a[2].second].push_back(a[2].first-a[1].first);
		}
		for(int k=1;k<=3;k++){
			if(b[k]>n/2){
				int m=b[k]-n/2;
				sort(p[k].begin(),p[k].end());
				for(int i=0;i<m;i++){
					ans-=p[k][i];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

