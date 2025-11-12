#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int T,n,tot,b[5][100005],cnt[5],flag,c[5],del[100005];
struct sd{
	int v,id,num;
	friend bool operator <(sd x,sd y){
		return x.v>y.v;
	}
}s[500005];
struct sp{
	int maxn,cmaxn;
}a[100005];
bool cmp(int x,int y){
	return a[x].maxn-a[x].cmaxn<a[y].maxn-a[y].cmaxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		tot=0;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(del,0,sizeof(del));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y,z; 
			scanf("%d%d%d",&x,&y,&z);
			s[++tot]=(sd){x,i,1};
			s[++tot]=(sd){y,i,2};
			s[++tot]=(sd){z,i,3};
			c[1]=x;
			c[2]=y;
			c[3]=z;
			sort(c+1,c+3+1);
			a[i].maxn=c[3];
			a[i].cmaxn=c[2];
		}
		sort(s+1,s+tot+1);
		for(int i=1;i<=tot;i++){
			if(del[s[i].id])	continue;
			del[s[i].id]=1;
			ans+=s[i].v;
			cnt[s[i].num]++;
			b[s[i].num][cnt[s[i].num]]=s[i].id;
		}
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		if(cnt[2]>n/2)	swap(b[1],b[2]),swap(cnt[1],cnt[2]);
		if(cnt[3]>n/2)	swap(b[1],b[3]),swap(cnt[1],cnt[3]);
		sort(b[1]+1,b[1]+cnt[1]+1,cmp);
		for(int i=1;i<=cnt[1]-n/2;i++){
			ans-=a[b[1][i]].maxn;
			ans+=a[b[1][i]].cmaxn;
		}
		printf("%lld\n",ans);
	}
	return 0;
}