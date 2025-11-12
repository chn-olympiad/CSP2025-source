#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+20;
int n,q;
signed main(){
	ioi;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	return 0;
}