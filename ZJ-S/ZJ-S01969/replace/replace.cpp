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
inline ll min(ll x,ll y){
	return x<y?x:y;
}
const int N=2e5+5;
ll T=1,n,q;
//ll num;
//unordered_map<string,ll>mp;
struct node{
	ll sz;
	string s1,s2;
}a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		q=read();
		for(int i=1;i<=n;i++){
			cin>>a[i].s1;
			cin>>a[i].s2;
			a[i].sz=a[i].s1.size();
//			a[i].s1=" "+a[i].s1;
//			a[i].s2=" "+a[i].s2;
//			if(!mp[a[i].s1]) mp[a[i].s1]=++num;
//			if(!mp[a[i].s2]) mp[a[i].s2]=++num;
		}
		string c1,c2;
		while(q--){
			ll ans=0,l=-1,r=0,siz;
			cin>>c1;
			cin>>c2;
			siz=c1.size();
			for(int i=0;i<siz;i++){
				if(c1[i]!=c2[i]){
					if(l==-1) l=i;
					r=i;
				}
			}
//			write(c1.size());
//			putchar(' ');
//			write(r);
//			putchar(' ');
//			write(l);
//			putchar(' ');
			for(int i=1;i<=n;i++){
				if(a[i].sz<r-l+1) continue;
				ll op=(a[i].sz-(r-l+1));
				for(int j=max(0,l-op);j<=min(l,siz-a[i].sz+1);j++){
					ll p=0,o=j;
					while(p<a[i].sz&&a[i].s1[p]==c1[j]&&a[i].s2[p]==c2[j]){
						p++;
						j++;
					}
					if(p==a[i].sz){
						ans++;
					}
					j=o;
				}
				
			}
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
