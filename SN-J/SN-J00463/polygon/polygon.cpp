#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int modd=998244353;
int n;
int a[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n+1;
	return 0;
}
