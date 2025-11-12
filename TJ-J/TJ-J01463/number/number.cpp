#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a,int b){
	if(a >= b){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<=s.size()-1;i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[s[i] - '0'] ++;
			
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=a[i];j++){
			cout<<i;
		}
	}
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	return 0;
} 
