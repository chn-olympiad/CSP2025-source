//SN-J01124  ChenYiguo 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s;
string b;
int cnt,sum;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s;
//	cout<<s[0];
	if(b[1]!='0'&&b[1]!='1'&&b[1]!='2'&&b[1]!='3'&&b[1]!='4'&&b[1]!='5'&&b[1]!='6'&&b[1]!='7'&&b[1]!='8'&&b[1]!='9'){
		cout<<s;
		

		return 0;
	}else if(b[2]!='0'&&b[2]!='1'&&b[2]!='2'&&b[2]!='3'&&b[2]!='4'&&b[2]!='5'&&b[2]!='6'&&b[2]!='7'&&b[2]!='8'&&b[2]!='9'){
	//	
		if(s[0]<s[1]){
			
			//cout<<s[0]<<" "<<s[1]<<" "<<s[2];
			cout<<s[1]<<s[0];
		
			return 0;
		}else{
		//	cout<<s[0]<<" "<<s[1]<<" "<<s[2];
			cout<<s[0]<<s[1];
			return 0;
		}
	}else if(b[3]!='0'&&b[3]!='1'&&b[3]!='2'&&b[3]!='3'&&b[3]!='4'&&b[3]!='5'&&b[3]!='6'&&b[3]!='7'&&b[3]!='8'&&b[3]!='9'){
	
		if(s[0]<s[1]&&s[1]<s[2]){//210
			cout<<s[2]<<s[1]<<s[0];
			return 0;
		}else if(s[0]>s[1]&&s[1]>s[2]){//012
			cout<<s[0]<<s[1]<<s[2];
			return 0;
		}else if(s[1]>s[2]&&s[2]>s[0]){
		//120
			cout<<s[1]<<s[2]<<s[0];
			return 0;
		}else if(s[1]<s[0]&&s[2]>s[0]){//201
			cout<<s[2]<<s[0]<<s[1];
			return 0;
		}else if(s[0]>s[2]&&s[2]>>s[1]){//021 
			cout<<s[0]<<s[2]<<s[1];
			return 0;
		}else if(s[1]>s[0]&&s[0]>s[2]){
			cout<<s[1]<<s[0]<<s[2];
			return 0;
		}
	}else if(b[4]!='0'&&b[4]!='1'&&b[4]!='2'&&b[4]!='3'&&b[4]!='4'&&b[4]!='5'&&b[4]!='6'&&b[4]!='7'&&b[4]!='8'&&b[4]!='9'){
	
		if(s[0]>s[3]){
			if(s[3]>s[2]){
				cout<<s[0]<<s[3]<<s[2]<<s[1];
				return 0;
			}else{
				cout<<s[0]<<s[3]<<s[1]<<s[2];
				return 0;
			}
			
		}else if(s[0]>s[1]){
			if(s[2]>s[3]){
				cout<<s[0]<<s[1]<<s[2]<<s[3];
				return 0;
			}else{
				cout<<s[0]<<s[1]<<s[3]<<s[2];
				return 0;
			}
			
		}else if(s[0]>s[2]){
			if(s[2]>s[1]){
				cout<<s[0]<<s[2]<<s[1]<<s[3];
				return 0;
			}else{
				cout<<s[0]<<s[2]<<s[3]<<s[1];
				return 0;
			}
			
		}else if(s[1]>s[0]){
			if(s[0]>s[2]){
				cout<<s[1]<<s[0]<<s[2]<<s[3];
				return 0;
			}else{
				cout<<s[1]<<s[0]<<s[3]<<s[2];
				return 0;
			}
			
		}else if(s[1]>s[3]){
			if(s[3]>s[0]){
				cout<<s[1]<<s[3]<<s[0]<<s[2];
				return 0;
			}else{
				cout<<s[1]<<s[3]<<s[2]<<s[0];
				return 0;
			}
			
		}else if(s[1]>s[2]){
			if(s[2]>s[3]){
				cout<<s[1]<<s[2]<<s[3]<<s[0];
				return 0;
			}else{
				cout<<s[1]<<s[2]<<s[0]<<s[3];
				return 0;
			}
			
		}else if(s[2]>s[0]){
			if(s[0]>s[1]){
				cout<<s[2]<<s[0]<<s[1]<<s[3];
				return 0;
			}else{
				cout<<s[2]<<s[0]<<s[3]<<s[1];
				return 0;
			}
			
		}else if(s[2]>s[1]){
			if(s[1]>s[0]){
				cout<<s[2]<<s[1]<<s[0]<<s[3];
				return 0;
			}else{
				cout<<s[2]<<s[1]<<s[3]<<s[0];
				return 0;
			}
			
		}else if(s[2]>s[3]){
			if(s[3]>s[0]){
				cout<<s[2]<<s[3]<<s[0]<<s[1];
				return 0;
			}else{
				cout<<s[2]<<s[3]<<s[1]<<s[0];
				return 0;
			}
			
		}else if(s[3]>s[0]){
			if(s[0]>s[1]){
				cout<<s[3]<<s[0]<<s[1]<<s[2];
				return 0;
			}else{
				cout<<s[3]<<s[0]<<s[2]<<s[1];
				return 0;
			}
			
		}else if(s[3]>s[1]){
			if(s[1]>s[0]){
				cout<<s[3]<<s[1]<<s[0]<<s[2];
				return 0;
			}else{
				cout<<s[3]<<s[1]<<s[2]<<s[0];
				return 0;
			}
			
		}else if(s[3]>s[2]){
			if(s[2]>s[0]){
				cout<<s[3]<<s[2]<<s[0]<<s[1];
				return 0;
			}else{
				cout<<s[3]<<s[2]<<s[1]<<s[0];
				return 0;
			}
			
		}
	}
	return 0;
}//AFO 9
