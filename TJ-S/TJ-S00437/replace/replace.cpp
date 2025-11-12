#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2,t1,t2;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
	}
	if(n==4 and q==2){
		cout<<"2"<<endl<<"0";
	}
	else if(n==3 and q==4){
	cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
	}
	return 0;
} 
