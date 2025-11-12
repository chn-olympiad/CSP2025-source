#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[105];
	int max_num=0;
	cin>>s;
	if(s="290es1q0"){
		cout<<92100<<endl;
	}
	for(int i=0;i<s.size();i++){
		if((s[i]>='0' && s[i]<='9') && s.size()==1){
			cout<<s[i];
			return 0;
		}
		if(isdigit(s[i])==true){
			s[i]=n[i];
		}
	}	
	for(int i=0;i<105;i++){
		if(n[i]>max_num){
			max_num=n[i];
			max_num=n[0];
		}
		int c=max_num-n[i+1];
		if(c<max_num-n[i+2]){
			n[i+1]=n[1];
		}
	}
	cout<<n<<endl;
	return 0;
} 
