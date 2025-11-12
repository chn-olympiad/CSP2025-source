#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans;
int a[100001][4];
int cnt[4],vis[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int mx=-1,pos=0,mi=-1,posi=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>mx){
					mi=mx;
					posi=pos;
					mx=a[i][j];
					pos=j;
				}else if(a[i][j]>mi){
					mi=a[i][j];
					posi=j;
				}
			}
			if(cnt[pos]<n/2){
				cnt[pos]++;
				vis[i]=pos;
				ans+=a[i][pos];
			}else{
				int posg=0,posd=0,mxx=-1;
				for(int j=1;j<=n;j++){
					if(vis[j]!=pos) continue;
					int mx2=-1,pos2=0;
					for(int k=1;k<=3;k++){
						if(k==pos) continue;
						if(mx2<a[j][k]){
							mx2=a[j][k];
							pos2=k;
						}
					}
					if(mi+a[j][pos]<mx+mx2){
						if(mxx<mx+mx2-(mi+a[j][pos])){
							mxx=mx+mx2-(mi+a[j][pos]);
							posg=j;
							posd=pos2;
						}
					}
				}
				if(mxx!=-1){
					ans+=mi;
					ans+=mxx;
					vis[posg]=posd;
					vis[i]=pos;
					cnt[posd]++;
				}else{
					vis[i]=posi;
					ans+=mi;
					cnt[posi]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 