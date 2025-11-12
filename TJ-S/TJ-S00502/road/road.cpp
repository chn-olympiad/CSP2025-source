#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long n,k,m,ans,cnt=0,x=0;
int g[10005][10005];
struct road{
	int a;
	int b;
	int w;
}s[100005];
bool cmp(struct road x,struct road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].a>>s[i].b>>s[i].w;
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(g[s[i].a][s[i].b]==0){
			ans+=s[i].w;
			g[s[i].a][s[i].b]++;
			g[s[i].b][s[i].a]++;
			for(int j=1;j<=n;j++){
				if(g[s[i].a][j]==1){
					cnt++;
					g[s[i].b][j]=1;
				}
			}
			if(cnt==n){
				x++;
				cnt=0;
			}
			for(int j=1;j<=n;j++){
				if(g[s[i].b][j]==1){
					cnt++;
					g[s[i].a][j]=1;
				}
			}
			if(cnt==n){
				x++;
				cnt=0;
			}
		}
		if(x==n) break;
	}
	cout<<ans;
	return 0;
}
