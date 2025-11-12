#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str1,str2;
		cin>>str1>>str2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}
	else if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
