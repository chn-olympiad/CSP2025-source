#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<"\n";
	return 0;
}
