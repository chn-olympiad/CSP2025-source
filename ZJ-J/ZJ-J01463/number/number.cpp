#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
bool cmp(char a,char b){
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+strlen(s));
	for(int i=strlen(s)-1;i>=0;i--)if(s[i]<='9'&&s[i]>='0')cout<<s[i];
	return 0;
}
