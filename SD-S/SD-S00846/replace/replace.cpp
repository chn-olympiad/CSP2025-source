#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,q;
string sx,sy;
string ax,bx;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>sx>>sy;
		for(int i=1;i<=q;i++){
			cin>>ax>>bx;
			cnt++;
		} 
	}
	cout<<cnt;
	return 0;
}

