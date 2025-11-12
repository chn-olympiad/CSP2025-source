#include<bits/stdc++.h>
using  namespace std;
long long int s[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	
	
	
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
		
			s[int(a[i]-'0')]++;
		}
	} 
		
	
	for(int i=9;i>=0;i--){
		if(s[i]!=0){
			for(int j=1;j<=s[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
