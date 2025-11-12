#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	int n;
	cin>>s;
	if(s.size()==1&&s[0]>='0'&&s[0]<='9'){
		int ans=s[0]-48;
		cout<<ans<<endl;
	}
	int m;
	7if(s.size()!=1){
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				n+=1;
				m=s[i];
			}	
		}
		if(n==1){
			cout<<m<<endl;
		}
	}else{cout<<0<<endl;}
	return 0;
}
