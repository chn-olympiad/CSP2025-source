#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	for(int i=n;i;i--)printf("%d",a[i]);
	return 0;
} 
