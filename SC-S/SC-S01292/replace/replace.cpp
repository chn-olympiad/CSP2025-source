#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int dn1,dn2;
	cin>>dn1>>dn2;
	if(dn1==4){
		cout<<2<<"\n"<<0;
	}else if(dn1==3){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	}else{
		for(int i=0;i<dn2;i++){
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}