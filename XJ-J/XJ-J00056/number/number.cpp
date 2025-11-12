#include<bits/stdc++.h>
using namespace std;
string s,z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n[s.size()],sum=0,c=0; 
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[i]=s[i]-'0';
			++c;
		}
		if(s[i]=='0'){
			sum++;
			++c;
		}
	}
	sort(n,n+s.size());
	for(long long i=c-1;i>=0;i--){
		if(n[i]==0){
			break;
		}else{
			cout<<n[i];
		}
	}
	if(sum!=0){
		for(long long i=0;i<sum;i++){
			cout<<0;
		}
	}
}
