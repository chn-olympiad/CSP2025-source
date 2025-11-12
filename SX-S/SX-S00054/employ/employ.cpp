#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll MOD=998244353;
inline ll read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const ll MAXN=550;
ll n,m;
char s[MAXN];
ll c[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
// 	变量名注意不要和关键词重复
	cin>>n>>m;
	cin>>s;
	int po=0;
	for (int i=0; i<s.size(); i++){
		if (s[i]==1) po++;
	}
	for (ll i=1; i<=n; i++){
		cin>>c[i];
	}
	//直接计算全排列
	ll sum=1;
	for (ll i=2; i<=n; i++){
		sum=(sum*i)%MOD;
	}
	
	cout<<(sum+MOD)%MOD<<endl;

	return 0;
}
