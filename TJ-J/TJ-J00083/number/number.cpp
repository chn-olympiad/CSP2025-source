#include<bits/stdc++.h>
using namespace std;
long long  a[11];
string s;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;	
		}else{
			continue;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			while(a[i]--){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
} 
