#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k,a[N];
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
ll now=0;
//现在要枚举a[x]，已经有cnt个区间，上一个元素有没有选过
ll dfs(int x,int cnt,bool chosen) {
	if(x==n+1) {
		if(chosen) return cnt+(now==k);
		else return cnt;
	}
	if(chosen) {
		if(now==k) {
			now=0;
			ll res1=dfs(x+1,cnt+1,0);
			ll now1=now;
			now^=a[x];
			ll res2=dfs(x+1,cnt+1,1);
			now=now1;
			return max(res1,res2);
		} else {
			ll now1=now;
			now^=a[x];
			ll res=dfs(x+1,cnt,chosen);
			now=now1;
			return res;
		}
	} else {
		//如果上一个没选可以选择开始一个新区间
		//或者继续不选
		ll res1=dfs(x+1,cnt,0);
		ll now1=now;
		now^=a[x];
		ll res2=dfs(x+1,cnt,1);
		now=now1;
		return max(res1,res2);

	}
}
ll f[N][5],tag[N][5];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1; i<=n; i++) {
		a[i]=read();
	}
	if(n<=10) {
		cout<<dfs(1,0,0);
		return 0;
	}
	for(int i=1; i<=n; i++) {
		//Case1,
		f[i][1]=max(f[i-1][1],f[i-1][3]);
		tag[i][1]=0;
		//Case2,
		f[i][2]=max(f[i-1][1],f[i-1][3]);
		tag[i][2]=a[i];

		//Case3,
		if(i==1);
		else {
			ll t=0;
			if(tag[i-1][2]==k) {
				t=max(t,f[i-1][2]+1);
			}
			if(tag[i-1][4]==k) {
				t=max(t,f[i-1][4]+1);
			}
			f[i][3]=t;
			tag[i][3]=0;
		}
		//Case4:
		if(i==1) ;
		else {
			if(f[i-1][2]>f[i-1][4]) {
				f[i][4]=f[i-1][2];
				tag[i][4]=tag[i-1][2]^a[i];
			} else {
				f[i][4]=f[i-1][4];
				tag[i][4]=tag[i-1][4]^a[i];
			}
		}

		//Case4不会了。好像有后效性。
		//直接使用贪心法消去（实则是懒得写

	}

	ll res1=f[n][1],res3=f[n][3];
	ll res2=f[n][2],res4=f[n][4];
	if(tag[n][2]==k) res2++;
	if(tag[n][4]==k) res4++;

	printf("%lld\n",max(max(res1,res2),max(res3,res4)));

	return 0;
}