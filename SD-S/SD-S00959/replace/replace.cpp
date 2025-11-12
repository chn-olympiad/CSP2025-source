#include<bits/stdc++.h>
using namespace std;
int n,q;
string x,y;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		long long ans=0;
		cin>>x>>y;
		for(int k=1;k<=n;k++){
			int len=a[k].size();
			for(int i=0;i<x.size();i++){
				bool flag=1;
				for(int j=0;j<len;j++){
					if(x[i+j]!=a[k][j]){
						flag=0;
						break;
					}
				}
				if(flag){
					for(int j=0;j<i;j++){
						if(x[j]!=y[j]) flag=0;
					}
					for(int j=0;j<len;j++){
						if(y[i+j]!=b[k][j]) flag=0;
					}
					for(int j=i+len;j<x.size();j++){
						if(x[j]!=y[j]) flag=0;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
