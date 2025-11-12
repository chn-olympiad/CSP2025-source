#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e6+10;
string s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len = s.size();
	long long cnt = 0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
			//cout<<s[i];
		}
			
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
		printf("%d",a[i]);
	return 0;
}
