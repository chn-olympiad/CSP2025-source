#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2*(int)1e5+10;
inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(int)(c-'0');
		c=getchar();
	}
	return x*w;
}
inline void print(ll x){
	char s[20];
	int top=0;
	if(x==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	if(x<0){
		x=-x;
		putchar('-');
	}
	while(x){
		top++;
		s[top]=(char)(x%10+'0');
		x/=10;
	}
	while(top){
		putchar(s[top]);
		top--;
	}
	putchar('\n');
}
int n,q,ans;
struct ns{
	string from,to;
	int l;
}s[maxn],t;
inline bool check(int j,int k){
	int l=s[j].l;
	string a=s[j].from,b=s[j].to;
	for(int i=0;i<k;i++){
		if(t.from[i]!=t.to[i])return 0;
	}
	for(int i=k+l;i<t.l;i++){
		if(t.from[i]!=t.to[i])return 0;
	}
	for(int i=k;i<k+l;i++){
		if(a[i-k]!=t.from[i])return 0;
	}
	for(int i=k;i<k+l;i++){
		if(b[i-k]!=t.to[i])return 0;
	}
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].from>>s[i].to;
		s[i].l=s[i].from.size();
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t.from>>t.to;
		t.l=(int)t.from.size();
		if((int)t.to.size()!=t.l){
			putchar('0');
			putchar('\n');
			continue;
		}
		for(int j=1;j<=n;j++){
			for(int k=0;k<=t.l-s[j].l;k++){
				if(check(j,k)){
					ans++;
				}
			}
		}
		print(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
