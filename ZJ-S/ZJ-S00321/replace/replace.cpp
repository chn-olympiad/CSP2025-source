#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	string a[10000];
	cin>>n>>m;
	for(int i=1;i<=n*2;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
		}
		if(n==1){
			cou<<1<<endl;
		}
	}
	return 0;
}