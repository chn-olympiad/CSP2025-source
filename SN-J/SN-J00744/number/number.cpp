#include<bits/stdc++.h>
using namespace std;


int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	int n;
	char s[n]={};
	cin>>n;	
	for(int i=1;i<=s.size();i++){
			cin>>s[i];	
		if(s[i]<=9&&s[i]<=s[i+1]){
			cout<<s[i+1];
		}
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
