#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],c;
bool V(int b,int a){
	return b>a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1,V);
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}
	return 0;
}