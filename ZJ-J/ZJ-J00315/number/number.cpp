#include<bits/stdc++.h>
using namespace std;
int tt=0;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')a[++tt]=s[i]-'0';
	}
	sort(a+1,a+1+tt,cmp);
	for(int i=1;i<=tt;i++)cout<<a[i];
	return 0;
}
