//SN-J101007  贾章泽 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int c,a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++) if(s[i]-'0'<=9&&s[i]-'0'>=0) a[++c]=s[i]-'0';
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--){
		cout<<a[i];
	} 
}
