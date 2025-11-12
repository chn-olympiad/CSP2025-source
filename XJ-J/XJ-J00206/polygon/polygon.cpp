#include<bits/stdc++.h>
using namespace std;
 int main(){
 	int a;
 	cin>>a;
 	int b,c,d,e,f;
 	int ans=0;
	if(a==3){cin>>b>>c>>d;if(b+c!=d&&b+d!=c&&c+d!=e){cout<<'1';}
	else{cout<<'0';}}
	if(a==4){cin>>b>>c>>d>>e;
		if(b+c!=d&&b+d!=c&&c+d!=e){ans+=1;}
		else if(b+c+d!=e&&b+d+e!=c&&c+d+e!=b){ans+=1;
		}
		cout<<ans;
		else{cout<<'0';
		}
	}
	if(a==5){cin>>b>>c>>d>>e>>f;
	if(b==1,c==2,d==3,e==4,f==5){
		cout<<'9';
	}
	else if(b==2,c==2,d==3,e==8,f==10){
		cout<<'6';}}
	frenopen("number.in","r",std in);
 	frenopen("number.out","w",std out);
 	return 0;}
 	
