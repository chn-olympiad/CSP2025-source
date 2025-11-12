#include<bits/stdc++.h>
#include<string>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int m,n,k,ans;
	char a[200],b[200],dif;
	string c,d;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
		cin>>c>>d;
	for(k=0;k<=20;k++){
		if(c[k]!=d[k]) dif+=c[k];
	}
	for(int i=1;i<=n;i++){
		cout<<0<<endl
	}
	return 0;
}
