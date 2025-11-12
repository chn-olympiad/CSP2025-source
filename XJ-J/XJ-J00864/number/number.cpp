#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int b[1000005],c[1000005],vis[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s=="1")
		cout<<1;
	if(s=="2")
		cout<<2;
	if(s=="3")
		cout<<3;
	if(s=="4")
		cout<<4;
	if(s=="5")
		cout<<5;
	if(s=="6")
		cout<<6;
	if(s=="7")
		cout<<7;
	if(s=="8")
		cout<<8;
	if(s=="9")
		cout<<9;
	int n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[i]=s[i];
	}
	for(int i=0;i<=n;i++){
		b[i]=a[i];
		c[i]=b[i]-48;
		vis[c[i]]++;		
	}
	for(int i=n+1;i>=0;i--){
		if(vis[i]!=0){
			for(int j=1;j<=vis[i];j++)
				cout<<i;
		}
	}
	return 0;
} 
