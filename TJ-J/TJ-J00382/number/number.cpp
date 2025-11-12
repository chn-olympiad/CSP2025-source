#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&& s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}

