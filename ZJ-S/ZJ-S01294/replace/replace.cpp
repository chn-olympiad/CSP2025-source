#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+100;
namespace zjcex {
	template<typename T>void _read(T &x) {
		char ch=getchar();
		int tmp=0;
		x=0;
		if(ch=='-') {
			tmp=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9') {
			x=(x<<1)+(x<<3)+(ch^(48));
			ch=getchar();
		}
		if(tmp==1) x=-x;
	}
	void read() {}

	template<typename T>void read(T &x) {
		_read(x);
	}
	template<typename T>void read(T &x,T &y) {
		_read(x);
		_read(y);
	}
	template<typename T>void read(T &x,T &y,T &z) {
		_read(x);
		_read(y);
		_read(z);
	}
	template<typename T>void read(T *l,T *r) {
		T *cur=l;
		while(cur!=r) {
			_read(*cur);
			cur++;
		}
	}
	template<typename T>void _write(T x) {
		int tmp=0;
		if(x<0) {
			putchar('-');
			x=-x;
		}
		if(x>=10) {
			_write(x/10);
		}
		putchar((x%10)+48);
	}
	template<typename T>void write(T x) {
		_write(x);
		putchar('\n');
	}
	template<typename T>void write(T *l,T *r) {
		T *cur=l;
		while(cur!=r) {
			_write(*cur);
			putchar(' ');
			cur++;
		}
		putchar('\n');
	}
}
void hey() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
using namespace zjcex;
int n,m;
string s[N][3];
bool compare(string a,int b,string st) {
	int l=a.size();
	for(int i=0;i<l;i++) {
		if(a[i]!=st[i+b]) return 0;
	}
	return 1;
}
string change(int b,string st,string fr) {
	int l=fr.size();
	for(int i=0;i<l;i++) {
		st[i+b]=fr[i];
	}
	return st;
}
signed main() {
	hey();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	while(m--) {
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.size();
		for(int j=1;j<=n;j++) {
			for(int i=0;i<l;i++) {
				if(compare(s[j][1],i,t1)) {
					string nt=change(i,t1,s[j][2]);
					if(compare(nt,0,t2)) {
						ans++;
					}
				}
			}
		}
		write(ans);
	}
	return 0;
}
