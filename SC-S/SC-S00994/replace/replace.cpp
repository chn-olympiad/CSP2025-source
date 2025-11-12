#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d,e,f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c>>d;
	}
	for(int i=1;i<=b;i++){
		cin>>e>>f;
	}
	for(int i=1;i<=a/2;i++){
		if(e.size()<=c.size()||e.size()<=d.size()||f.size()<=c.size()||f.size()<=d.size()) cout<<'0';				
	}
	for(int i=1;i<=a/2;i++){
		if(c[i]==e[i]&&d[i]==f[i]) cout<<'2'<<endl;
		else cout<<'5';
	}
	return 0;
}