#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,a[maxn][10],t[10],g[maxn],maxx,b[maxn],pos,c[maxn],cnt;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cnt=0;
		t[1]=0,t[2]=0,t[3]=0;
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				t[1]++;
				g[i]=1;
				maxx+=a[i][1];
				c[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				t[2]++;
				g[i]=2;
				maxx+=a[i][2];
				c[i]=a[i][2]-max(a[i][3],a[i][1]);
			}
			else{
				t[3]++;
				g[i]=3;
				maxx+=a[i][3];
				c[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
			cout<<maxx<<'\n';
			continue;
		}
		if(t[1]>n/2) pos=1;
		if(t[2]>n/2) pos=2;
		if(t[3]>n/2) pos=3;
		for(int i=1;i<=n;i++){
			if(g[i]==pos){
				b[++cnt]=c[i];
			}
		}
		sort(b+1,b+cnt+1);
		for(int i=1;i<=t[pos]-n/2;i++){
			maxx-=b[i];
		}
		cout<<maxx<<'\n';
	}
	return 0;
}


