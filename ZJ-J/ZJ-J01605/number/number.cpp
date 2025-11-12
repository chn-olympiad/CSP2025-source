#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000001],t;
char c[1000001];
bool cmp(int t,int w){
	return t>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c+1;n=strlen(c+1);
	for(i=1;i<=n;i++)
		if(c[i]>='0'&&c[i]<='9'){
			a[++t]=(c[i]-'0');
		}
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
