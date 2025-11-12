#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100010;
int a[N][4],b[N],p[N];
int cnt[4],tmp[N];
bool cmp(int x,int y){
	return b[x]<b[y];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int res=0;
		for(int i=1;i<=n;i++){
			int mx=0,id=0;
			for(int j=1;j<=3;j++)
				cin>>a[i][j],mx=max(mx,a[i][j]);
			for(int j=1;j<=3;j++){
				if(a[i][j]==mx)
					id=j;
			}
			res+=mx;
			cnt[id]++;
		}
		int m=n/2;
		if(cnt[1]<=m&&cnt[2]<=m&&cnt[3]<=m){
			cout<<res<<'\n';
		}else{
			res=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=n;j++){
					int mx=0;
					for(int k=1;k<=3;k++)
						if(k!=i)mx=max(mx,a[j][k]);
					b[j]=mx-a[j][i];
					p[j]=j;
					tmp[j]=mx;
				}
				sort(p+1,p+n+1,cmp);
				int ans=0;
				for(int j=m+1;j<=n;j++)
					ans+=tmp[p[j]];
				for(int j=1;j<=m;j++)
					ans+=a[p[j]][i];
				res=max(res,ans);
			}	
			cout<<res<<'\n';
		}
		cnt[1]=cnt[2]=cnt[3]=0;
	}
	return 0;
}
