#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	int n=read(),q=read();
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
//oh ccf I love you
//I hope you could let me go to NOIP 
//shuan Q
