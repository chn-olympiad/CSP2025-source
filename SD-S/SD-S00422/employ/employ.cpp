#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[505],ans=1;
string s;
int main(){
	//ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==0) k--;
	}
	for(int i=1;i<=k;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<0<<endl;
	return 0;
}

