#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int j=0;
for(int i=0;i<s.length();i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[j++]=s[i];
	}
}
sort(a,a+j);
	for(int i=j;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9'){
			cout<<a[i];
		}
	}
return 0;


}
