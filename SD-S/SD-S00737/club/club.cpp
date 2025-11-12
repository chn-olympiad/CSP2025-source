#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N][5],vis[N];
struct node{
	int c,p;
}t[N];
bool cmp(node a,node b){
	return a.c>b.c;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		int n,flg=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++){
			ans=0;
			memset(vis,0,sizeof(vis));
			int cnt=0;
			for(int j=1;j<=n;j++){
				int maxx=-1;
				for(int k=1;k<=3;k++) if(k!=i) maxx=max(maxx,a[j][k]);
				t[j].c=a[j][i]-maxx,t[j].p=j;
				if(t[j].c>0) cnt++;
			}
			if(cnt<=n/2) continue;
			flg=1;
			sort(t+1,t+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				vis[t[j].p]=1;
				ans+=a[t[j].p][i];
			}
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				int t1=0,t2=0;
				for(int k=1;k<=3;k++){
					if(k==i) continue;
					if(!t1) t1=a[j][k];
					else t2=a[j][k];
				}
				ans+=max(t1,t2);
			}
			break;
		}
		if(flg){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		cout<<ans<<"\n"; 
	} 
	return 0;
}
/*
1.注意空间限制，不要MLE
2.易错题要对拍
3. */
