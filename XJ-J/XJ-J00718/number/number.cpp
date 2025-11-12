#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxvv=1e6+5;
int a[maxvv],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<=l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt]=s[i]-48;
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
		printf("%d",a[i]);
	return 0;
} 
