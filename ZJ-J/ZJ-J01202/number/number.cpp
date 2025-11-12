#include<bits/stdc++.h>
using namespace std;
string s;
long long len,tot,a[1000001];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		cout<<a[i];
}
