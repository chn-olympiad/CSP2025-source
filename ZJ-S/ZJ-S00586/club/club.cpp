#include<bits/stdc++.h>
#define int long long
#define rg register
#define gc getchar
#define pc putchar
using namespace std;
const int inf=0x3f3f3f3f;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int N=1e5+10;
struct node{
	int d[3];
	int mx,id,se;
}a[N],b[N];
bool cmp(node x, node y){
	return x.mx-x.se>y.mx-y.se;
}
int n,cnt[3];
inline void solve(){
	n=read();
	cnt[0]=cnt[1]=cnt[2]=0;
	for(rg int i=1;i<=n;i++){
		a[i].mx=0;
		for(rg int j=0;j<3;j++){
			a[i].d[j]=read();
			if(a[i].d[j]>a[i].mx){
				a[i].mx=a[i].d[j];
				a[i].id=j;
			}
		}
		cnt[a[i].id]++;
	}
	bool flag=0;int pos=0;
	for(rg int i=0;i<3;i++){
		if(cnt[i]>n/2){
			flag=1,pos=i;
			break;
		}
	}
	if(!flag){
		int res=0;
		for(rg int i=1;i<=n;i++) res+=a[i].mx;
		write(res);puts("");
		return;
	}
	int tot=0,ans=0;
	for(rg int i=1;i<=n;i++){
		if(a[i].id^pos) ans+=a[i].mx;
		else{
			b[++tot]=a[i],b[tot].se=0;
			for(rg int j=0;j<3;j++){
				if(j^pos) b[tot].se=max(b[tot].se,a[i].d[j]);
			}
		}
	}
	sort(b+1,b+1+tot,cmp);
	for(rg int i=1;i<=n/2;i++) ans+=b[i].mx;
	for(rg int i=n/2+1;i<=tot;i++) ans+=b[i].se;
	write(ans);puts("");
	for(rg int i=1;i<=tot;i++){
		b[i].mx=b[i].se=b[i].id=0;
		for(rg int j=0;j<3;j++) b[i].d[j]=0;
	}
	for(rg int i=1;i<=n;i++){
		a[i].mx=a[i].id=0;
		for(rg int j=0;j<3;j++) a[i].d[j]=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
