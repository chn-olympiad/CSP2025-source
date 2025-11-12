#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IO{
	inline ll read(){
		ll res=0;
		bool flg=true;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-') flg=false;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			res=(res<<3)+(res<<1)+(c&15);
			c=getchar();
		}return flg?res:-res;
	}
	inline void print(ll num){
		if(num>9) print(num/10);
		putchar('0'+num%10);
		return;
	}
	inline void write(ll num){
		if(num<0) putchar('-'),num=-num;
		print(num);
		putchar('\n');
		return;
	}
}
using namespace IO;
const int kMaxN=1e5+5;
struct N{
	ll w;
	int tp;
	inline bool friend operator<(N x,N y){
		return x.w>y.w;
	}
}a[kMaxN][4];
int n,cnt[4];
ll ans=0;
priority_queue<ll> pq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,i,j,p,tmp;
	T=read();
	for(;T;--T){
		n=read(),ans=0;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;++i) for(j=1;j<=3;++j) a[i][j].w=read(),a[i][j].tp=j;
		for(i=1;i<=n;++i) sort(a[i]+1,a[i]+3+1);
		for(i=1;i<=n;++i){
			ans+=a[i][1].w;
			++cnt[a[i][1].tp];
		}
		tmp=n/2,p=0;
		if(cnt[1]>tmp) p=1;
		else if(cnt[2]>tmp) p=2;
		else if(cnt[3]>tmp) p=3;
		if(!p){
			write(ans);
			continue;
		}
		while(!pq.empty()) pq.pop();
		for(i=1;i<=n;++i){
			if(a[i][1].tp==p)
				pq.push(a[i][2].w-a[i][1].w);
		}
		while(cnt[p]>tmp){
			ans+=pq.top();
			pq.pop();
			--cnt[p];
		}
		write(ans);
	}
	return 0;
}
