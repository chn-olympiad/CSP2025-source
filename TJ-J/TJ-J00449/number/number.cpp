#include<bits/stdc++.h>
using namespace std;
int a[1000005],j;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[j]=int(s[i]-48),j++;
	}
	sort(a,a+j);
	while(j--)printf("%d",a[j]);
return 0;}
