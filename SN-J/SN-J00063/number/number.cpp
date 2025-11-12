//SN-J00063
#include<bits/stdc++.h>
using namespace std;
const int fyc=1e6+5;
char s[fyc];
int len;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s+1;
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]<'0'||s[i]>'9') s[i]=0;
	sort(s+1,s+len+1,cmp);
	for(int i=1;s[i]>='0';i++) cout<<s[i];
	return 0;
}
