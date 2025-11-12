#include<bits/stdc++.h>
#define ll long long
using namespace std;ll n,ans=1;
const int MOD=998244353;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)(ans*=i)%=MOD;
	cout<<ans;
	return 0;
}/*Oi生涯结束了，但我却什么也没留下
警戒后人，不要虚度光阴，不然会像我这样一事无成*/