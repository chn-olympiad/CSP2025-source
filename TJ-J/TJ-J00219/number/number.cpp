#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9')a[i]=s[i]-48;
		if(s[i]=='0')c++;
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++)if(a[i]>=1&&a[i]<=9)cout<<a[i];
	for(int i=0;i<c;i++)cout<<0;
	return 0;
}
