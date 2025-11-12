#include<bits/stdc++.h>
using namespace std;
int a[1001]={0};
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
		for(int i=10;i>=0;i--){
		    if(a[i]>=1){
		    	for(int x=1;x<=a[i];x++){
		    		cout<<i;
				}
		    }
		
		
		
	}

	
	
} 
