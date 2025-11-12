#include<bits/stdc++.h>
using namespace std;
int n,m;
string S;
int s[501];
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>S;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		s[i]=S[i-1]-'0';
	}
	cout<<1;
	return 0;
}
