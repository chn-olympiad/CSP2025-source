#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n[100005],j=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			j++;
			n[j]=s[i]-'0';
		} 
	}
	sort(n,n+j+1);
	for(int i=j;i>=1;i--){
		cout<<n[i];
	}
	return 0;
}
