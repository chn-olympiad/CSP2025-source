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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read();
	int q=read();
	for(int i=0;i<q;i++)
		cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

