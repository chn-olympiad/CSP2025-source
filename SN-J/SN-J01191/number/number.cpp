#include<bits/stdc++.h>
#define ll long long 
using namespace std;

char s[2000001]={};
ll a[2000001]={};
ll l=0,p=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
	l=strlen(s);
	for(ll i=0;i<=l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[p]=s[i]-'0';p++;
		}	
	}
	sort(a,a+p+1);
	for(ll i=p;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

