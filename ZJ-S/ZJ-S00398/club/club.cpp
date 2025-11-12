#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][3],con[3],ans,b[N],c[N],d[N],l=0,e[100],ll=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0,l=0;
		memset(con,0,sizeof(con));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>max(a[i][1],a[i][2])) con[0]++,c[i]=0,b[i]=a[i][0]-max(a[i][1],a[i][2]);
			if(a[i][1]>max(a[i][0],a[i][2])) con[1]++,c[i]=1,b[i]=a[i][1]-max(a[i][0],a[i][2]);
			if(a[i][2]>max(a[i][0],a[i][1])) con[2]++,c[i]=2,b[i]=a[i][2]-max(a[i][0],a[i][1]);
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		for(int i=0;i<3;i++){
			if(con[i]>n/2){
				for(int j=1;j<=n;j++){
					if(c[j]==i) d[++l]=b[j];
				}
				sort(d+1,d+1+l);
				for(int j=1;con[i]>n/2;j++){
					con[i]--;
					ans-=d[j];
				}
				break;
			}
		}
		e[++ll]=ans;
	}
	for(int i=1;i<=ll;i++) printf("%d\n",e[i]);
	return 0;
}
//s-00398
