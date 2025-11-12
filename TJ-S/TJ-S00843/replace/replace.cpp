#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,q;
string a[N],b[N];
string x,y;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cin>>b[i];
	}
	while(q--){
		cin>>x;
		cin>>y;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int k=0;k<x.size();k++){
				if(x.substr(k,a[i].size())==a[i]){
					for(int j=k;j<=k+a[i].size()-1;j++) x[j]=b[i][j-k];
					if(x==y) cnt++;
					for(int j=k;j<=k+a[i].size()-1;j++) x[j]=a[i][j-k];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
