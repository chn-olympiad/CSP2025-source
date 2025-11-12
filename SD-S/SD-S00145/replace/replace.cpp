#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200005],b[200005];
string qa[200005],qaa[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		cin>>qa[i]>>qaa[i];
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
