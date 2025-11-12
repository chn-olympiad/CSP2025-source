#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N][5],b[5],c[N],d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		b[1]=b[2]=b[3]=0;
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;++i){
			int mx=0;
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
				mx=max(mx,a[i][j]);
			}
			ans+=mx;
			for(int j=1;j<=3;++j){
				if(mx==a[i][j]){
					c[i]=j;
					b[j]++;
					break;
				}
			}
		}
		int mmx=max(b[1],max(b[2],b[3]));
		if(mmx<=n/2){
			printf("%d\n",ans);
			continue;
		}
		int cnt=mmx-n/2,p;
		for(int i=1;i<=3;++i)if(mmx==b[i])p=i;
		int tot=0;
		for(int i=1;i<=n;++i){
			if(c[i]!=p)continue;
			int mx=0;
			for(int j=1;j<=3;++j){
				if(j==p)continue;
				mx=max(mx,a[i][j]);
			}
			d[++tot]=a[i][p]-mx;
		}
		sort(d+1,d+tot+1);
		for(int i=1;i<=cnt;++i)ans-=d[i];
		printf("%d\n",ans);
	}
	return 0;
}
