#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
namespace abc_{

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}

struct node{
	ll a,b,c;
}e[N];
int t,n,mx,cnt[3];
bool cmp(node x,node y){
	if(x.a==y.a)
		if(x.b==y.b) return x.c>y.c;
		else return x.b>y.b;
	else return x.a>y.a;
}
bool cmp2(node x,node y){
	if(x.a==y.a) return x.a+y.b>y.a+x.b;
	else return x.a>y.a;
}
void work1(){
	ll ans=0;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=max(e[i].a,max(e[i].b,e[i].c));
	}
	cout<<ans<<"\n";
	return ;
}
void work2(){
	ll ans=0;
	int mx=n/2;
	sort(e+1,e+n+1,cmp2);
	for(int i=1;i<=n;i++){
		int x=e[i].a,y=e[i].b,z=e[i].c;
		if(x>y&&cnt[0]<mx) ans+=x,cnt[0]++;
		else if(y>x&&cnt[1]<mx) ans+=y,cnt[1]++;
		else if(cnt[0]<mx) ans+=x,cnt[0]++;
		else if(cnt[1]<mx) ans+=y,cnt[1]++;
	}
	cout<<ans<<"\n";
	return ;
}
int my_main(){
	t=read();
	while(t--){
		n=read();
		mx=n/2;
		ll ans=0;
		cnt[1]=cnt[2]=cnt[0]=0;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			e[i].a=read(),e[i].b=read(),e[i].c=read();
			if(e[i].c) f1=0,f2=0;
			if(e[i].b) f1=0;
			if(!e[i].a) f1=f2=0;
		}
		if(f1){
			work1();
			continue;
		}
		if(f2){
			work2();
			continue;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=e[i].a,y=e[i].b,z=e[i].c;
			if(x>y&&x>z&&cnt[0]<mx) ans+=x,cnt[0]++;
			else if(y>x&&y>z&&cnt[1]<mx) ans+=y,cnt[1]++;
			else if(z>y&&z>x&&cnt[2]<mx) ans+=z,cnt[2]++;
			else if(cnt[0]<mx) ans+=x,cnt[0]++;
			else if(cnt[1]<mx) ans+=y,cnt[1]++;
			else if(cnt[2]<mx) ans+=z,cnt[2]++;
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	abc_::my_main();
	return 0;
}
