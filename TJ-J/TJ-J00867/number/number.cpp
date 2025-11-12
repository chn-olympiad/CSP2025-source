#include <bits/stdc++.h>
using namespace std;
string s,b;
int x[15],a; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			x[s[i]-48]++;
			a++;
		}
	}
	cout<<b;
	for(int i=9;i>=0;i--){
		if(x[i]>0){
			for(int j=1;j<=x[i];j++){
				b+=i+48;
			}
		} 
	}
	cout<<b;
	
	return 0;
}
