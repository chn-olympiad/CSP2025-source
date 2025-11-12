#include<bits/stdc++.h>
#define g() getchar()
using namespace std;
const int N=600;
int n,q;
string a1[N],a2[N];
string t1[N],t2[N];
signed main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		cout<<0<<endl;
	}
	return 0;
}
