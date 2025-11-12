#include<bits/stdc++.h>
using namespace std;
int len,i,j,f[10];
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	len=strlen(s+1);
	for(i=1;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9')f[s[i]-48]++;
	for(i=9;i>=0;i--){
		for(j=1;j<=f[i];j++)cout<<i;
	}
}
