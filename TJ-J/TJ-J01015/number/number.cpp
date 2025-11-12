#include<bits/stdc++.h>
using namespace std;
long long n[10000000],m,d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0 ;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			n[m]=s[i]-'0';
			m+=1;
		}
	}
	for(long long i=1;i<m;i++){
		for(long long j=0;j<m-i;j++){
			if(n[i-1]>n[i+j]){
				d=n[i-1];
				n[i-1]=n[i+j];
				n[i+j]=d;
			}
		}
	}
	for(long long i=m-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
