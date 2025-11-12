#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N],d[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,sum=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=i;
	}
	cout<<sum;
	return 0;
}
