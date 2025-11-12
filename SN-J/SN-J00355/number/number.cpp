#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[100005],o,n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')
		a[++o]=s[i]-'0';
	}
	sort(a+1,a+o+1,cmp);
	for(int i=1;i<=o;i++)
	cout<<a[i];
	return 0;
}
