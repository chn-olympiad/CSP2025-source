//SN-J01002   贺宇轩  西安市经开第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	//	freopen("","r",stdin);
	//	freopen("","w",stdout);
	int s,a,b,c,d,e,f,g;
	int s1,s2,s3,s4,s5,s6,s7=0;
	cin>>s;
	s1=s/1000000;
	s2=s/100000%10;
	s3=s/10000%10;
	s4=s/1000%10;
	s5=s/100%10;
	s6=s/10%10;
	s7=s%10;
	if(s1>s2&&s1>s3&&s1>s4&&s1>s5&&s1>s6&&s1>s7){
		cout<<s1;
	}
	else if(s2>s1&&s2>s3&&s2>s4&&s2>s5&&s2>s6&&s2>s7){
		cout<<s2;
	}
	else if(s3>s1&&s3>s2&&s3>s4&&s3>s5&&s3>s6&&s3>s7){
		cout<<s3;
	}
	else if(s4>s1&&s4>s3&&s4>s2&&s4>s5&&s4>s6&&s4>s7){
		cout<<s4;
	}
	else if(s6>s1&&s5>s3&&s5>s4&&s5>s2&&s5>s6&&s5>s7){
		cout<<s5;
	}
	else if(s6>s1&&s6>s3&&s6>s4&&s6>s5&&s6>s2&&s6>s7){
		cout<<s6;
	}
	else if(s7>s1&&s7>s3&&s7>s4&&s7>s5&&s7>s6&&s7>s2){
		cout<<s7;
	}
	
	
	
	if(s1>s3&&s1>s4&&s1>s5&&s1>s6&&s1>s7){
		cout<<s1;
	}
	else if(s2>s3&&s2>s4&&s2>s5&&s2>s6&&s2>s7){
		cout<<s2;
	}
	else if(s3>s2&&s3>s4&&s3>s5&&s3>s6&&s3>s7){
		cout<<s3;
	}
	else if(s4>s3&&s4>s2&&s4>s5&&s4>s6&&s4>s7){
		cout<<s4;
	}
	else if(s5>s3&&s5>s4&&s5>s2&&s5>s6&&s5>s7){
		cout<<s5;
	}
	else if(s6>s3&&s6>s4&&s6>s5&&s6>s2&&s6>s7){
		cout<<s6;
	}
	else if(s7>s3&&s7>s4&&s7>s5&&s7>s6&&s7>s2){
		cout<<s7;
	}
	
	
	if(s1>s4&&s1>s5&&s1>s6&&s1>s7){
		cout<<s1;
	}
	else if(s2>s4&&s2>s5&&s2>s6&&s2>s7){
		cout<<s2;
	}
	else if(s3>s4&&s3>s5&&s3>s6&&s3>s7){
		cout<<s3;
	}
	else if(s4>s2&&s4>s5&&s4>s6&&s4>s7){
		cout<<s4;
	}
	else if(s5>s4&&s5>s2&&s5>s6&&s5>s7){
		cout<<s5;
	}
	else if(s6>s4&&s6>s5&&s6>s2&&s6>s7){
		cout<<s6;
	}
	else if(s7>s4&&s7>s5&&s7>s6&&s7>s2){
		cout<<s7;
	}
	
	
	
	if(s1>s4&&s1>s5&&s1>s6&&s1>s7){
		cout<<s1;
	}
	else if(s2>s4&&s2>s5&&s2>s6&&s2>s7){
		cout<<s2;
	}
	else if(s3>s4&&s3>s5&&s3>s6&&s3>s7){
		cout<<s3;
	}
	else if(s4>s2&&s4>s5&&s4>s6&&s4>s7){
		cout<<s4;
	}
	else if(s5>s4&&s5>s2&&s5>s6&&s5>s7){
		cout<<s5;
	}
	else if(s6>s4&&s6>s5&&s6>s2&&s6>s7){
		cout<<s6;
	}
	else if(s7>s4&&s7>s5&&s7>s6&&s7>s2){
		cout<<s7;
	}
	return 0;
}
