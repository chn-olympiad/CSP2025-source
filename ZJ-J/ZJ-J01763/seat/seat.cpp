#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110,M=15;
ll a[N],sq[M][M],test,n,m,x=1,y=1,hei;
bool cmp(ll x,ll y){return x>y;}
int main(){
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	test=a[1];sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		sq[x][y]=a[i];
		if(sq[x][y]==test){cout<<y<<" "<<x<<"\n";return 0;}
		!hei?x++:x--;
		if(x>n) hei=1,x--,y++;
		if(x<=0) hei=0,x++,y++;
	}
	cout<<"WoW\n";
	return 0;
}