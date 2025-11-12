#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio;cin.tie(0);cout.tie(0);
	int n,a,b,c,q=0;
	cin >> n >> a >> b >> c;
	if(a+b<c) q++;
	if(a+c<b) q++;
	if(b+c<a) q++;
	cout << q;
	return 0;
}
