#include<bits/stdc++.h>
//#pragma GCC	optimize(2)
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

int t, n, ans, x, y, z;
vector<int> cnt(4, 1);
vector<vector<int> > a(100010, vector<int>(3));
vector<vector<int> > pre(100010, vector<int>(4));

void calc(vector<int> &pre, int x, int y, int z){
	int a, b, c;
	a=max(x, max(y, z));
	if(a==x) b=max(y, z), c=min(y, z);
	if(a==y) b=max(x, z), c=min(x, z);
	if(a==z) b=max(y, x), c=min(y, x);
	if(a==x) pre[0]=1;
	else if(a==y) pre[0]=2;
	else pre[0]=3;
	if(b==x) pre[1]=1;
	else if(b==y) pre[1]=2;
	else pre[1]=3;
	if(c==x) pre[2]=1;
	else if(c==y) pre[2]=2;
	else pre[2]=3;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		for(int i=1;i<=n;++i){
			x=read(), y=read(), z=read();
			a[i][0]=x, a[i][1]=y, a[i][2]=z;
			calc(pre[i], x, y, z);
			cout<<pre[i][0]<<endl;
			++cnt[pre[i][0]];
		}
		for(int i=1;i<=n;++i){
			ans+=a[i][pre[i][0]];
		}
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}