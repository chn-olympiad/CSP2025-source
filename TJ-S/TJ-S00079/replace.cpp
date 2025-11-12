#include<bits/stdc++.h>
using namespace std;
string arr[200005][200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.in","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string sx,sy;
		cin>>sx>>sy;
		for(int j=1;j<=q;j++){
			string tx,ty;
			cin>>tx>>ty;
			swap(sx,sy);
			swap(tx,ty);
			swap(sx,ty);
			swap(tx,sy);
		}
	}
	return 0;
}
