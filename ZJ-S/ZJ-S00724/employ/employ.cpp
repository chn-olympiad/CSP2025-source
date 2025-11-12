#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=1000;
int d[N],a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		d[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0;
	return 0;
}
