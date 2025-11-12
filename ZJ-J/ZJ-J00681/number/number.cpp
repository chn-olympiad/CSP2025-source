#include<bits/stdc++.h>
using namespace std;
int a[3000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin>>s;
	for(int i=0;i<s.size();i++)if(isdigit(s[i]))t+=s[i];
	for(int i=0;i<t.size();i++)a[i]=t[i]-'0';
	sort(a,a+t.size(),cmp);
	for(int i=0;i<t.size();i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
