#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int T,n,cnt[3],ans;
int pos[maxn],c[maxn];
struct GYY{
	int id,w;
}a[maxn][3];
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
bool cmp(int x,int y){return x>y;}
bool cmp1(GYY x,GYY y){return x.w>y.w;}
void change(int x){
	int k=0;
	for(int i=1;i<=n;i++){
		if(pos[i]==x)c[++k]=a[i][1].w-a[i][0].w;
	}
	sort(c+1,c+1+k,cmp);
	for(int i=1;i<=cnt[x]-n/2;i++)ans+=c[i];
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i][0].w=read();a[i][1].w=read();a[i][2].w=read();
		a[i][0].id=0;a[i][1].id=1;a[i][2].id=2;
		sort(a[i],a[i]+3,cmp1);
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i][0].id<<" "<<a[i][1].id<<" "<<a[i][2].id<<endl;
//	}
	memset(cnt,0,sizeof cnt);
	memset(pos,0,sizeof pos);ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][0].w;
		cnt[a[i][0].id]++;
		pos[i]=a[i][0].id;
	}
//	cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
	int now=-1;
	if(cnt[0]>n/2)now=0;
	if(cnt[1]>n/2)now=1;
	if(cnt[2]>n/2)now=2;
	if(now==-1){printf("%d\n",ans);return;}
//	cout<<now<<endl;
	change(now);
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}