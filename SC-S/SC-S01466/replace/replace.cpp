#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
int n,q;
string a[mx],b[mx],qa,qb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		int s=0;
		cin>>qa>>qb;
		string x="",y="",z="",ta="",tb="";
		int k=qa.length();
		for(int i=0;i<k;i++)
			if(qa[i]!=qb[i]) ta+=qa[i],tb+=qb[i];
		for(int i=1;i<=n;i++){
			if(ta==a[i]&&tb==b[i]) s++;
		}
		cout<<s<<endl;	
	}
	return 0;
}             