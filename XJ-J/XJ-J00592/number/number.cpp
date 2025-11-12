#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			while(a[i]!=0){
				cout<<i;
				a[i]--;
			}
		}
	}
	return 0;
} 
