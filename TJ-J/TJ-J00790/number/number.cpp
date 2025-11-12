#include<bits/stdc++.h>
using namespace std;
int g=0,a[1000005];
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<=s.size()-1;i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[g]=s[i]-'0';
		g++;
	}
}
sort(a,a+g);
for(int i=g-1;i>=0;i--){
    cout<<a[i];
}
return 0;
}
