#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a,b;
	cin>>n>>q;
	int fla[n+3]={},fra[n+3]={},flb[n+3]={},frb[n+3]={};
	for(int i=0;i<n;i++){
		cin>>a>>b;
		fla[i]=a.find('b');
		fra[i]=a.size()-fla[i]-1;
		flb[i]=b.find('b');
		frb[i]=b.size()-flb[i]-1;
	}
	while(q--){
		string xx,yy;
		int flx=0,frx=0,fly=0,fry=0,sum=0;
		cin>>xx>>yy;
		flx=xx.find('b');
		frx=xx.size()-flx-1;
		fly=yy.find('b');
		fry=yy.size()-fly-1;
		for(int i=0;i<n;i++){
			if(fla[i]<=flx&&fra[i]<=frx&&flb[i]<=fly&&frb[i]<=fry){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
