#include<bits/stdc++.h>
using namespace std;
long long n,q;
void check(string x,string y,string a,string b){
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string st[n+2][3];
	for(int i=1;i<=n;i++){
		cin>>st[i][1]>>st[i][2];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int la=a.length();
		int lb=b.length();
		if(la>lb){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			string x=st[i][1],y=st[i][2];
			check(x,y,a,b);
		}
		cout<<0<<endl;
	}
	return 0;
}
