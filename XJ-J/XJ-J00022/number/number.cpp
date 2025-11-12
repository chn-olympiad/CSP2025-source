#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],i=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=0;j<s.length();j++)if(s[j]>='0'&&s[j]<='9')a[i++]=s[j]-'0';
	sort(a+1,a+i,cmp);
	for(int j=1;j<i;j++)cout<<a[j];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
