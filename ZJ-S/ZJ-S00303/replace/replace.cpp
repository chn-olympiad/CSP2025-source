#include <iostream>
using namespace std;
int n,q,ans;
string tmp,tmp2,x,a[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		ans=0;
		cin>>tmp>>tmp2;
		if(tmp.size()!=tmp2.size()){
			cout<<0;
			if(q!=0){
				cout<<'\n';
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			x=tmp;
			auto t=x.find(a[i][0]);
			if(t==string::npos) continue;
			x.erase(t,a[i][0].size());
			x.insert(t,a[i][1]);
			if(x==tmp2){
				ans++;
			}
		}
		cout<<ans;
		if(q!=0){
			cout<<'\n';
		}
	}
	return 0;
}

