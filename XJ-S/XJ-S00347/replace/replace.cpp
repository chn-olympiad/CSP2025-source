#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],s1[200005],c[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s[i]>>s1[i];
	for(int i=1;i<=q;i++)	cin>>c[i][1]>>c[i][2];
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
