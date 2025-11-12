#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int c=1;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	c--;
	sort(a+1,a+1+c);
	if(a[c]==0) cout<<0;
	else{
		for(int i=c;i>=1;i--) cout<<a[i];
	}
	return 0;
}
