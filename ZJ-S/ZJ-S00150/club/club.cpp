#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],b[N],c[N],cnt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		for(int i=0;i<3;++i){
			cnt[i]=0;
		}
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				scanf("%d",&a[i][j]); 
			}	
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int mx=a[i][0],id=0;
			for(int j=1;j<3;++j){
				if(a[i][j]>mx){
					mx=a[i][j];
					id=j;
				}
			}
			cnt[id]++;
			ans=ans+mx;
			b[i]=id;
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
			printf("%d\n",ans);
			continue; 
		}
		int id;
		for(int i=0;i<3;++i) if(cnt[i]>n/2) id=i;
		int m=0;
		for(int i=1;i<=n;++i){
			if(b[i]==id){
				int mx=-1;
				for(int j=0;j<3;++j) if(j!=id) mx=max(a[i][j],mx);
				c[++m]=a[i][id]-mx;
			} 
		}
		sort(c+1,c+1+m);
		for(int i=1;i<=cnt[id]-n/2;++i) ans-=c[i];
		printf("%d\n",ans); 
	}
	return 0;
} 
