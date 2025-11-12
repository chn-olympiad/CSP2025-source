#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int a[1000005],z;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9')a[z++]=s[i]-'0';
	}
	sort(a,a+z,cmp);
	for(int i=0;i<z;i++)cout<<a[i];
	return 0;
}
