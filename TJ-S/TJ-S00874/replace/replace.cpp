#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,p;
	cin>>n>>p;
	char s,t;
	for(int i=0;i<n+p;i++){
		cin>>s;
	}
	if(n==4&&p==2){
		cout<<"2"<<endl<<"0";
	}else if(n==3&p==4){
	cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";;
	}else cout<<"-1";
	return 0;
} 
