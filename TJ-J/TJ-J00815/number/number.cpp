#include<bits/stdc++.h>
using namespace std;
int a,b[1000002],d;
string s;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>=48&&s[i]<58)b[d++]=s[i]-48;
	}
	sort(b,b+d);
	for(int i=d-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}

