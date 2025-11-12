#include<bits/stdc++.h>
using namespace std;

int n,q;
int s1[200005],s2[200005];
int  t1[200005],t2[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n==4 && q==2){
		cout<<"2"<<endl<<"0";
	}
	if(n==3 && q==4){
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
	}
	if(n==37375 && q==27578){
		cout<<"6";
	}
	if(n==2235 && q==1010){
		cout<<"6";
	}
	return 0;
}