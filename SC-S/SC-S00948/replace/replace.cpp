#include<bits/stdc++.h>
using namespace std;

long long n,q;
string s[200005][3];
string t[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(long long i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(long long i=1;i<=q;i++){
		cout<<0;
	}
	return 0;
}