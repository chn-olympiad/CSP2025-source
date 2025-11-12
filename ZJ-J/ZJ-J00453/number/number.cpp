#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],c=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[c++]=s[i]-'0';
		}
	}
	sort(a+1,a+c,cmp);
	for(int i=1;i<c;i++){
		cout<<a[i];
	}
	return 0;
}
