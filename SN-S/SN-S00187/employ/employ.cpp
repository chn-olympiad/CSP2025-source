#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>p;
	cout<<(n*m*p)% 998244353;
	return 0;
}
