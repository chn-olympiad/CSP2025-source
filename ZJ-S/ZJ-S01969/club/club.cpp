#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline ll max(ll x,ll y){
	return x>y?x:y;
}
const int N=1e5+5;
ll T=1,n,b[5],c[N];
struct node{
	ll x,y,z;
	bool operator< (const node& g) const {
		return y<g.y;
	}
}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ll ans=0;
		n=read();
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++){
			ll x=read(),y=read(),z=read();
			if(x>=y&&x>=z){
				a[i].z=1;
				a[i].x=x;
				a[i].y=x-max(y,z);
				b[1]++;
			}else if(y>=x&&y>=z){
				a[i].z=2;
				a[i].x=y;
				a[i].y=y-max(x,z);
				b[2]++;
			}else{
				a[i].z=3;
				a[i].x=z;
				a[i].y=z-max(x,y);
				b[3]++;
			}
		}
		ll m=(n>>1);
		if(b[1]<=m&&b[2]<=m&&b[3]<=m){
			for(int i=1;i<=n;i++){
				ans+=a[i].x;
			}
			write(ans);
			putchar('\n');
			continue;
		}
		ll p,k;
		for(int i=1;i<=3;i++){
			if(b[i]>m){
				p=i;
				k=b[i]-m;
				break;
			}
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i].z==p&&k>0){
				k--;
				ans+=(a[i].x-a[i].y);
			}else ans+=a[i].x;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
