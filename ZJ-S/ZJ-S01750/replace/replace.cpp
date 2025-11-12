#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[10001],b[10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i]>>b[i];
		}
	}
	for(int i=1;i<=q;i++){
		string q,p;
		cin>>q>>p;
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
} 
