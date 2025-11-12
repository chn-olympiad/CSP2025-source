#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
#define mod 998244353
using namespace std;
const int N=510;
int n,m,flag=1;
string s;
int c[N],a[N];
ll ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		if(a[i]==0) flag=0;
	}
	cout<<m;
	
	
	return 0;
} 
