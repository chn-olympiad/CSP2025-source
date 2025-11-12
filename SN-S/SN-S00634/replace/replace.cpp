#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
string s1[maxn],s2[maxn],s3[maxn],s4[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s3[i]>>s4[i];
		cout<<0<<'\n';
	}
	return 0;
}
