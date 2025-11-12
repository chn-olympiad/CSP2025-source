#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=105;
int n,m,cnt,a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])cnt++;
	}if(cnt%(2*n)==0){
		cout<<cnt/n<<' '<<n<<'\n';
		return 0;
	}int x=cnt%(2*n);
	int y=cnt/(2*n)*2;
	if(x<=n)cout<<y+1<<' '<<x<<'\n';
	else cout<<y+2<<' '<<2*n-x+1<<'\n';
	return 0;
}
