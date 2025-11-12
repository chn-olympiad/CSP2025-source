#include<bits/stdc++.h>
using namespace std;
map<string,string> a;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s,c;
		cin>>s>>c;
		a[s]=c;
	}
	while(q--){
		string x,y;
		int cnt=0;
		cin>>x>>y;
		if(a[x]==y)cnt++;
		int xx=0,yy=0;
		for(int i=0;i<=x.size()-1;++i){
			if(x[i]=='b'){
				xx=i;
				break;
			}
		}
		for(int i=0;i<=y.size()-1;++i){
			if(y[i]=='b'){
				yy=i;
				break;
			}
		}
		for(int i=1;i<=x.size();++i){
			string s="";
			for(int j=0;i<=j && j<=abs(xx-yy);++j){
				s=s+x[i];
			}
			if(a[s]!="")cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

