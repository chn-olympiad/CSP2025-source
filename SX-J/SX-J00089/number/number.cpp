#include<bits/stdc++.h>
using namespace std;
int i,n=0,a[1000]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;;i++){
		if(s[i]==' '){
			break;
		}
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[n]=s[i];
			n++;
		}
	}
	sort(a+n,a+n+1);
	for(i=0;i<=n;i++)
		cout<<a[n];
	return 0;
}