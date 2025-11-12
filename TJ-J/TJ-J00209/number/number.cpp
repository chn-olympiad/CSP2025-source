#include<bits/stdc++.h>
using namespace std;


string s,s1;
long long ans; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
//		cout<<s[i];
		if(s[i] >= '0' and s[i]<='9'){
			ans++;
			s1+=s[i]; 
		}
	}
	
	sort(s1.begin(),s1.end());
	for(int i=ans-1;i>=0;i--){
		cout<<s1[i];
	}
	
	return 0;
} 
