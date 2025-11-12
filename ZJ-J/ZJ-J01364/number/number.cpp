#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++d]=s[i]-48;
		}
	}
	sort(a+1,a+1+d);
	for(int i=d;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}