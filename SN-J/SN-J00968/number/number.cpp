#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10005],x[10005],c=0,mx=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[c]=s[i]-48;
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c;i>=0;i--){
		mx=mx*10+a[i];
	}
	cout<<mx;
	return 0;
}
