#include<bits/stdc++.h>
using namespace std;
int a[1000010],i,t,n;
char s[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=t;i++) cout<<a[i];
	return 0;
}
