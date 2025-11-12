#include<bits/stdc++.h>
#pragma GCC	optimize(2)
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int mod=998244353;
int n, m, sum;
string s;
int date[512], c[512], cnt0[512], cnt[512];

void solve(int remain, int day){
	if(day>n){
		if(remain>=m) ++ans;
		return;
	}
	solve()
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(), m=read();
	cin>>s;
	s=' '+s;
	memset(cnt,-1,sizeof cnt);
	memset(date,m,sizeof date);
	for(int i=1;i<=n;++i){
		sum+=!(s[i]-'0');
		if(!(s[i]-'0')) cnt0[sum]=i;
	}
	for(int i=1;i<=n;++i) c[i]=read(), ++cnt[c[i]];
	sort(c+1, c+n+1);
	for(int i=1;i<=n;++i)
	return 0;
//	for(int i=1;i<=n;++i) 
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
//3 2
//101
//1 1 2