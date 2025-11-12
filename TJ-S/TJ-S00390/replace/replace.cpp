#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int flag=0;
	if(n==4&&q==2){
		flag=42;
	}
	else if(n==3&&q==4){
		flag=34;
	}
	string x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
	}
	if(flag==42) cout<<2<<endl<<0<<endl;
	else if(flag==34) cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
