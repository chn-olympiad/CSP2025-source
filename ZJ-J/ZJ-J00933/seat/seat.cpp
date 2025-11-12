#include<bits/stdc++.h>//¨H¡È¡é|
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
typedef long long Int;

Int n,m,a1,a,pos=0;

int main(){
	IOS;OpenFile(seat);

	cin>>n>>m>>a1;
	for(Int i=2;i<=n*m;i++)cin>>a,pos+=(a>a1);
	if((pos/n+1)&1)cout<<pos/n+1<<" "<<pos%n+1<<endl;
	else cout<<pos/n+1<<" "<<n-pos%n<<endl;
	

	return 0;
}

