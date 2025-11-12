#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
int a[1000005];
int cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=int(s[i]-48);
			cnt++;
		}
	}
	sort(a+1,a+cnt,greater<int>());
	for(int i=1;i<cnt;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
