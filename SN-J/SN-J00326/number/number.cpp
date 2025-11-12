#include<bits/stdc++.h>
using namespace std;
string s,q;
int t=0,c=0; 
string a[1005],b[1005];
string ans;
int main(){
	//freeopen("number.in","r",stdin);
	//freeopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
				a[i]=s[j];
				q=s[j];
				c+=1;
			}
			if(a[i]>=q){
				t+=1;
			}
		}
		if(t==c){
			ans+=s[i];
			
		}
	}
					
	cout<<ans;
	return 0;
} 
