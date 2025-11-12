#include <bits/stdc++.h>
using namespace std;
const int V=1e9;
int n=10000,m=1000000,k=10;
mt19937_64 rd(time(0));
int main(){
	freopen("test.in","w",stdout);
	cout<<n<<" "<<m<<" "<<k<<"\n";
	for(int i=1;i<=m;i++){
		cout<<rd()%n+1<<" "<<rd()%n+1<<" "<<rd()%V<<"\n";
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cout<<rd()%V<<" ";
		cout<<"\n";
	}
	return 0;
}