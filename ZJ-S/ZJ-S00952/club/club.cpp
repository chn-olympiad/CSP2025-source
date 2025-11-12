#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,a[maxn][5],cnt[10],d[maxn],sum,vis[maxn],v[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int f=max(a[i][1],max(a[i][2],a[i][3]));
			int g=min(a[i][1],min(a[i][2],a[i][3]));
			int x,y;
			if(f==a[i][1]){
				x=1;
				if(g==a[i][2]) y=3;
				else y=2;
			}
			else if(f==a[i][2]){
				x=2;
				if(g==a[i][1]) y=3;
				else y=1;
			}
			else if(f==a[i][3]){
				x=3;
				if(g==a[i][1]) y=2;
				else y=1;
			}
			sum+=a[i][x];
			d[i]=a[i][x]-a[i][y];
			cnt[x]++;
			vis[i]=x;
		}
		int b=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>=cnt[b]) b=i;
		}
		int k=0;
		if(cnt[b]>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==b){
					v[++k]=d[i];
				}
			}
			sort(v+1,v+k+1);
			int c=cnt[b]-n/2;
			//cerr<<v[1]<<"\n";
			for(int i=1;i<=c;i++) sum-=v[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}