#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000001];
long long int a;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
     cin>>s;
     for(int i=0;i<=s.size();i++){
     	if(s[i]>=48&&s[i]<=57){
     		a++;
     		n[a]=s[i]-48;
		 }
	 }sort(n,n+a+1);
	 for(int i=a;i>=1;i--){
	 	cout<<n[i];
	 }
	return 0;
}
