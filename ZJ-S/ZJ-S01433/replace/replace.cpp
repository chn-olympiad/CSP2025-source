#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string a[N][2];
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][0].size()>x.size()) continue;
			int posx=x.find(a[i][0]);
			if(posx==-1) continue;
			if(x.substr(0,posx)+a[i][1]+x.substr(posx+a[i][1].size())!=y) continue;
			cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
