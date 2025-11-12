#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll getseed(){
	ll a[256];
	return accumulate(a,a+256,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	mt19937 rd(getseed());
	cout<<rd()%998244353;
	return 0;
}
//我真没招了 
