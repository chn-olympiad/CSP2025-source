#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],b[3][N],ans;
int typ,t1,t2;
struct node{
	int val,t,nmb;
}p[N];
int cnt[3],used[N];
bool cmp(node lhs,node rhs){
	return lhs.val<rhs.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			used[i]=0;
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int mx=max(a[i][0],max(a[i][1],a[i][2])); 
			if(mx==a[i][0])b[0][++cnt[0]]=i;
			else if(mx==a[i][1])b[1][++cnt[1]]=i;
			else if(mx==a[i][2])b[2][++cnt[2]]=i;
		}
		ans=0;
		if(cnt[0]*2<=n&&cnt[1]*2<=n&&cnt[2]*2<=n){
			for(int i=1;i<=n;i++)ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}else{
			//printf("NO\n");
			if(cnt[0]*2>n)typ=0;
			else if(cnt[1]*2>n)typ=1;
			else if(cnt[2]*2>n)typ=2;
			//printf("typ%d\n",typ);
			t1=(typ+1)%3,t2=(typ+2)%3;
			for(int i=1;i<=cnt[typ];i++){
				int j=b[typ][i],c1=a[j][t1]-a[j][typ],c2=a[j][t2]-a[j][typ];
				//printf("j%d\n",j);
				if(c1>c2)p[i]={c1,t1,j};
				else p[i]={c2,t2,j};
			}
			sort(p+1,p+cnt[typ]+1,cmp);
			for(int i=1;i<=cnt[typ];i++){
				//printf("nmb%d\n",p[i].nmb);
				if(i<=n/2)ans+=a[p[i].nmb][typ];
				else ans+=a[p[i].nmb][p[i].t];
			}
			for(int i=1;i<=cnt[t1];i++)ans+=a[b[t1][i]][t1];
			for(int i=1;i<=cnt[t2];i++)ans+=a[b[t2][i]][t2];
		}
		printf("%d\n",ans);
	}
	return 0;
}
