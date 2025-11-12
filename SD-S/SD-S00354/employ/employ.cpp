#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define MaxN 500
#define MOD 998244353
using namespace std;
ll n,m,cnt,tmp,ans,c[MaxN],a[MaxN];
char s[MaxN];
bool Jud(){
	cnt=0,tmp=0;
	for(ll i=1;i<=n;i++){
		if(tmp>=c[a[i]]){
			tmp++;
			continue;
		}
		else {
			if(s[a[i]]=='1')cnt++;
			else tmp++;
		}
		if(cnt>=m)return 1;
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>s[i];
	for(ll i=1;i<=n;i++)cin>>c[i],a[i]=i;
	do{
		ans=(ans+Jud())%MOD;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}

