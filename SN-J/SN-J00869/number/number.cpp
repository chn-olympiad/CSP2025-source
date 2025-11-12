#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cc=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cc++]=s[i]-'0';
		}
	}
	int cnt=cc-1;
	sort(a,a+cnt,cmp);
	for(int i=0;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
