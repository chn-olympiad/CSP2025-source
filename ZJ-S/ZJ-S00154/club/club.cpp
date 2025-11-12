#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n,cnt[5],ans;
struct node{
	int bh,de;
}p[N];
int Max(int x,int y){
	return x>y?x:y;
}
node init(int a,int b,int c){
	if(a>=b&&a>=c){
		ans+=a;
		return (node){1,a-Max(b,c)};
	}
	if(b>=c&&b>=a){
		ans+=b;
		return (node){2,b-Max(a,c)};
	}
	if(c>=a&&c>=b){
		ans+=c;
		return (node){3,c-Max(a,b)};
	}
}
bool cmp(node x,node y){
	return x.de<y.de;
}
void find(int x){
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(p[i].bh!=x) continue;
		if(cnt[x]<=(n>>1)) break;
		ans-=p[i].de;
		--cnt[x];
		if(cnt[x]<=(n>>1)) break;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	int a,b,c;
	while(T--){
		scanf("%d",&n);
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a,&b,&c);
			p[i]=init(a,b,c);
			++cnt[p[i].bh];
		}
		for(int i=1;i<=3;++i){
			if(cnt[i]<=(n>>1)) continue;
			find(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
