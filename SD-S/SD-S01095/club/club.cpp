#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+26,inf=-1e6;
int T,n,a[mxn][3],ans,mx[mxn],cnt[3],p[mxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			ans+=(mx[i]=max({a[i][0],a[i][1],a[i][2]}));
			if(mx[i]==a[i][0])
				cnt[p[i]=0]++;
			else if(mx[i]==a[i][1])
				cnt[p[i]=1]++;
			else
				cnt[p[i]=2]++;
		}
		if((mx[0]=max({cnt[0],cnt[1],cnt[2]}))>n/2){
			if(mx[0]==cnt[0])
				p[0]=0;
			else if(mx[0]==cnt[1])
				p[0]=1;
			else
				p[0]=2;
			for(int i=1;i<=n;i++){
				mx[0]=inf;
				if(p[i]==p[0])
					for(int j=0;j<3;j++)
						if(j!=p[0])
							mx[0]=max(mx[0],a[i][j]-mx[i]);
				mx[i]=mx[0];
			}
			sort(mx+1,mx+n+1);
			for(int i=n+n/2-max({cnt[0],cnt[1],cnt[2]})+1;i<=n;i++)
				ans+=mx[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
20min
*/
