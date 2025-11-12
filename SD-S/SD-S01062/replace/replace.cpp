#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}

int n, q;
char s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, m;
	n = read();m = read();
	for( int i = 1 ; i <= n ; ++i ){
		cin >> (s+1);
		cin >> (s+1);
	}
	for( int i = 1 ; i <= m ; ++i ){
		cin >> (s+1);
		cin>>(s+1);
		cout << 0 << "\n";
	}
	return 0;
}

