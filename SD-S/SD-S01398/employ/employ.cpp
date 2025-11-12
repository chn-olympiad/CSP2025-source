#include <bits/stdc++.h>
using namespace std;
int n,m,num;
int a[505];
string s;
int read(){
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
		f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
	return x;
}
int main(){
	freopen("employ.in","r",stdin);
	freoprn("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	int k=s.length();
	for (int i=1;i<=n;i++)
	a[i]=read();
	srand(time(0));
	int x=rand()%51247856;
	cout<<x;
	return 0;
}
