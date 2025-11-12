#include<bits/stdc++.h>
using namespace std;
int a[1001111];
string s;
int cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ll=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++ll]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ll,cmp);
	for(int i=1;i<=ll;i++){
		printf("%d",a[i]);
	}
	return 0;
}