#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010], len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--)	
		printf("%d",a[i]);
	return 0;
} 
