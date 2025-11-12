#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010]={0},l=0;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int leng=s.length();
	for(int i=0;i<leng;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[l++]=s[i]-'0';
		}
	}
	sort(a+0,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}