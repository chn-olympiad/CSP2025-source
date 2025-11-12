#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int P=998244353;
int n,m;
string s;
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=m;i++){
		ans*=i;
		ans%=P;
	}
	cout<<ans;
	return 0;
} 
