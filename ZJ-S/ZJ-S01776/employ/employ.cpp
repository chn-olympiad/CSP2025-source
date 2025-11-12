#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
using namespace std;
const int maxn=1e3+10;
const int mod=998244353;
int n,m;
char ch;
bitset<maxn>s;
bool flag=0;
int c[maxn];
int p(int num){
	int x=1;
	for(int i=2;i<=num;i++)x=(x*i)%mod;
	return x;
}
int RP=INF;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	++RP;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=(ch=='1'?1:0);
		if(ch=='0')flag=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(flag){
		cout<<p(n);
		return 0;
	}
	
	return 0;
}
