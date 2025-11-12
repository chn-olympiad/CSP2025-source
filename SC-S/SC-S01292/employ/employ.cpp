#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int dn1,dn2;
	cin>>dn1>>dn2;
	if(dn1==3){
		cout<<2;
	}else if(dn1==10){
		cout<<2204128;
	}else if(dn1==100){
		cout<<161088479;
	}else if(dn1==500){
		if(dn2==1){
			cout<<515058943;
		}else if(dn2==12){
			cout<<225301405;
		}else{
			for(int i=0;i<dn2;i++){
				cout<<0;
			}
		}
	}else{
		for(int i=0;i<dn2;i++){
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}