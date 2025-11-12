#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N];
int ans;
int e[N],f[N];
bool fl,ua,ub;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string c,d;
		cin>>c>>d;
		if(c.size()!=d.size()){
			cout<<0<<'\n';
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			string x="";
			for(int j=0;j+a[i].size()-1<c.size();j++){
				string y=x;
				for(int k=0;k<a[i].size();k++){
					if(c[j+k]!=a[i][k])break;
					if(k==a[i].size()-1){
						x+=b[i];
						for(int l=j+a[i].size();l<c.size();l++){
							x+=c[l];
						}
						if(x==d)ans++;
					}
//					cout<<j<<' '<<k<<' '<<x<<'\n';
				}
				x=y;
				x+=c[j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}