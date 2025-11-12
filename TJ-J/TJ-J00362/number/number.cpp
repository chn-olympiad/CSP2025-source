#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cin>>s;
	int qjs=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[qjs]=int(s[i]-'0');
			qjs++;
		}
	}
	int m=a[0];
	sort(a,a+1+qjs); 
	for(int i=qjs;i>0;i--)cout<<a[i];
	
	fclose(stdin);
    fclose(stdout);
    return 0;
} 
