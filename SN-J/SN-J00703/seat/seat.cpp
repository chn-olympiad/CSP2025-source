#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int n,m,a[110],ans;
string main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			ans++;
		}
	}
	int x=1,y=0,fl=1;
	while(ans--){
		y+=fl;
		if(y<1||y>n){
			x++;
			y-=fl;
			fl=-fl;
		}
	}
	cout<<x<<' '<<y<<'\n';
	return "J组就是试机111";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB()<<'\n';
}
