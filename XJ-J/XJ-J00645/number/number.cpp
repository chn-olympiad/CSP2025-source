#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0;
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]+0>47 && s[i]+0<58){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
