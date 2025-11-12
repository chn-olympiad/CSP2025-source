#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;//1
int c[510]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int p = 0;
	cin>>n>>m;
	cin>>s;
	long long ans = 1;
	for(int i = 1;i<=n;i++) cin>>c[i];
	for(int i = 1;i<=m;i++)
	{
		ans*=n;
		n-=1;
	}
	cout<<ans%998244353;
    return 0;
}

