#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=1e5+10;
struct node{
	int mid,cid,xid,cz1,cz2;
};
int T,n,a[N][6];
node ifm[N];
ll ans;
bool cmp(int x,int y){
	return ifm[x].cz1>ifm[y].cz1;
}
void solve(){
	ans=0;
	cin>>n;
	int len[5]={},g[5][N]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ifm[i].mid=1;
			if(a[i][2]>=a[i][3]) ifm[i].cid=2,ifm[i].xid=3;
			else ifm[i].cid=3,ifm[i].xid=2;
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			ifm[i].mid=2;
			if(a[i][1]>=a[i][3]) ifm[i].cid=1,ifm[i].xid=3;
			else ifm[i].cid=3,ifm[i].xid=1;
		}else{
			ifm[i].mid=3;
			if(a[i][1]>=a[i][2]) ifm[i].cid=1,ifm[i].xid=2;
			else ifm[i].cid=2,ifm[i].xid=1;
		}
		ifm[i].cz1=a[i][ifm[i].mid]-a[i][ifm[i].cid];
		ifm[i].cz2=a[i][ifm[i].cid]-a[i][ifm[i].xid];
		g[ifm[i].mid][++len[ifm[i].mid]]=i;
		while(1){
			int f=-1;
			for(int k=1;k<=3;k++){
				if(len[k]>(n/2)){
					f=k;
					break;
				}
			}
			if(f==-1) break;
			sort(g[f]+1,g[f]+len[f]+1,cmp);
			for(int k=n/2+1;k<=len[f];k++){
				int j=g[f][k];
				if(ifm[j].mid==f){
					ifm[j].cz1=ifm[j].cz2;
					g[ifm[j].cid][++len[ifm[j].cid]]=j;
					g[f][k]=0;
				}else{
					ifm[j].cz1=-1;
					g[ifm[j].xid][++len[ifm[j].xid]]=j;
					g[f][k]=0;
				}
			}
			len[f]=n/2;
		}
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=len[i];j++){
			ans+=a[g[i][j]][i];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
