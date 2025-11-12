#include<bits/stdc++.h>
#define pb push_back
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e5+5;
int n,t,a[N][4],b[N];
vector<int>vec[4];
void sol(){
	n=rd();
	int ans=0;
	for(int i=1;i<=3;i++)vec[i].clear();
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=3;j++)a[i][j]=rd(),mx=max(mx,a[i][j]);
		for(int j=1;j<=3;j++)
			if(a[i][j]==mx){
				vec[j].pb(i);
				ans+=mx;
				break;
			}
	}
	for(int i=1;i<=3;i++){
		for(auto x:vec[i]){
			b[x]=0;
			for(int j=1;j<=3;j++)if(i^j)b[x]=max(b[x],a[x][j]);
		}
		sort(vec[i].begin(),vec[i].end(),[&](int x,int y){
			return a[x][i]-b[x]<a[y][i]-b[y];
		});
		if(vec[i].size()>n/2){
			for(int j=0;j<vec[i].size()-n/2;j++)
				ans-=a[vec[i][j]][i]-b[vec[i][j]];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(t=rd();t--;)sol();
	return 0;
}