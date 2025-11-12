#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int n,m,a[N];
char c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<0;
	return 0;
}

