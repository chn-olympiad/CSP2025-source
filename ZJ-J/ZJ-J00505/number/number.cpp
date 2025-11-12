#include<bits/stdc++.h>
using namespace std;
char s[1111111];
int n,v[12];
int main() {
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++) if(s[i]>='0' && s[i]<='9') v[s[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=v[i];j++) putchar(i+'0');
	cout<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}