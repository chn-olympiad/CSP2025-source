#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int i,t,sss;
char s[N],s2[N];
bool cmp(char q,char h){
	return q>h;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<int(strlen(s));i++)
		if(s[i]>='0'&&s[i]<='9') s2[t++]=s[i];
	sort(s2,s2+t,cmp);
	cout<<s2;
	return 0;
}
