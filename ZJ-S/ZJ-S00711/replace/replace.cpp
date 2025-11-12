#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010],b[200010],x,y;
bool X(int fi,int fj,int k){
	if(a[k].size()!=(fj-fi+1))return 0;
	for(int i=fi;i<=fj;i++)
		if(x[i]!=a[k][i-fi])return 0;
	return 1;
}
bool Y(int fi,int fj,int k){
	if(b[k].size()!=(fj-fi+1))return 0;
	for(int i=fi;i<=fj;i++)
		if(y[i]!=b[k][i-fi])return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		int ans=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<'\n';
			continue;
		}
		int i,j;
		for(i=0;i<x.size();i++)
			if(x[i]!=y[i])break;
		for(j=x.size()-1;j>=0;j--)
			if(x[j]!=y[j])break;
		for(int oi=0;oi<=i;oi++)
			for(int oj=j;oj<x.size();oj++)
				for(int k=1;k<=n;k++)
					if(X(oi,oj,k)&&Y(oi,oj,k))
						ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
