#include<bits/stdc++.h>
using namespace std;
int a[1000008]={};
int cmp(int a,int b){
	if(a<b) return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n,j=0;
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]-'0'<=9) a[j++]=s[i]-'0';
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++) printf("%d",a[i]);

	return 0;
}
