#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,L=2007;
int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<(n-(n/m)*(n%m)/2) > 0 ? (n-(n/m)*(n%m)/2) : ((n/m)*(m/2)+(n%m)*(n%m))<<"\n";
	return 0;
}
