#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(NULL));
const int mx=10;
int T,n;
int main(){
	freopen("test.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	T=1000;
	cout<<T<<"\n";
	while(T--){
		n=6;
		cout<<n<<"\n";
		for(int i=1;i<=n;i++){
			int x,y,z;
			x=rd()%mx+1;
			y=rd()%mx+1;
			z=rd()%mx+1;
			cout<<x<<" "<<y<<" "<<z<<"\n";
		}
	}
	return 0;
}
