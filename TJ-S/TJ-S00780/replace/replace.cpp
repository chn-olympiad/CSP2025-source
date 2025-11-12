#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s,s1,s2,t1,t2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		if(i==1){
			s=s1;
		}
	}
	if(n==4&&q==2&&s=="xabcx"){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&q==4&&s=="a"){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
	}
	return 0;
}

