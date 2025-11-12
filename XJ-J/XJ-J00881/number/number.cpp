#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long
const int N=1e6+5;
string str;
int a[N];
LL n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9')a[++n]=str[i]-'0';
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
} 
