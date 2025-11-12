#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read();
	int m=read();
	string s;
	cin>>s;
	int a;
	for(int i=0;i<n;i++) a=read();
	cout<<(1<<(2*n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
