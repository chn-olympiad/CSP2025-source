#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return f*x;
}int _s[20],_t;
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	do _s[++_t]=x%10,x/=10;
	while(x);while(_t)putchar(_s[_t--]+48);
	return;
}
const int N=5e6+5;
int n,q,k,f1,f2,l,l1;
char c;
unordered_map<int,vector<pii> >mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++){
		c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			++l;
			if(c=='b')f1=l;
			c=getchar();
		}
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			++l;
			if(c=='b')f2=l;
			c=getchar();
		}
		mp[f1-f2].push_back({f1-1,l-f1});
	}for(pair<int,vector<pii > >p:mp){
		sort(mp[p.fi].begin(),mp[p.fi].end());
	}
	for(int i=1;i<=q;i++){
		c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			++l;
			if(c=='b')f1=l;
			c=getchar();
		}
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			++l1;
			if(c=='b')f2=l1;
			c=getchar();
		}
		if(l!=l1){
			putchar('0'),putchar('\n');
			continue;
		}
		vector<pii >&vc=mp[f2-f1];
		int x=f1-1,y=l-f1,cnt=0;
		for(pii t:vc){
			if(t.fi<=x)if(t.se<=y)cnt++;
			else break;
		}
		wt(cnt),putchar('\n');
	}
	return 0;
}

