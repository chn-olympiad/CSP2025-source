#include<bits/stdc++.h>
using namespace std;
long long  a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;	
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[s[i]-'0']++;
		}	
	}
	for(int i=9;i>=0;){
		if(a[i]==0){
			i--;
		}else{
			cout<<i;
			a[i]--;	
		} 
	}
	 
	return 0;
}
