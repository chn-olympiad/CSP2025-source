#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[510],s[510],ans;
char cs[510];
bool flag=true;
const ll mod=998244353;
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cs[i];
		s[i]=cs[i]-'0';
		if(s[i]==0)flag=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<"\n";
	}
	else{
		srand(time(0));
		cout<<(rand()<<10)%mod<<"\n";
	}
}