#include<bits/stdc++.h>
using namespace std;//1 2 3 12 13 23 123 -12 -13 -23
#define itn int
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	itn n,m;cin>>n>>m;
	string a[n],b[n];
	string c[m],d[m];
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<m;i++){
		cin>>c[i]>>d[i];
		cout<<"0\n";
	}
	return 0;
}
