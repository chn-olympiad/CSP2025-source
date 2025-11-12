#include<bits/stdc++.h>
using namespace std;
string s;int a[1000002],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9){
			a[b++]=s[i]-'0';
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--)cout<<a[i];
	return 0;
}
