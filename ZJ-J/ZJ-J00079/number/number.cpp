#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int t,a[1000001];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	for(int i=1;i<=strlen(s+1);i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++t]=s[i]-'0';
	sort(a+1,a+t+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
