#include<bits/stdc++.h>
using namespace std;
string s;
long long l,len=0,a[10000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[len]=s[i]-'0';
			len++;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}