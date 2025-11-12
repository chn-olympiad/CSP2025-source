#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt=0;
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	for(int i=0;i<s.size();i++){
		
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
		}else{
			s[i]='0';
		}
	}
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<i;j++){
			if(s[i]>=s[j]){
				int mun=s[i];
				s[i]=s[j];
				s[j]=mun;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<s[i];
	}
	return 0;
} 
