#include<bits/stdc++.h>
#pragma GCC optimize(2,3,4,5,6,7,"Ofast")
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
string a;
int f[11];
int main(){
  freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)if(a[i]>='0'&&a[i]<='9')f[a[i]-48]++;
	for(int i=9;i>=0;i--)
		while(f[i]--)cout<<i;
	return 0;
}
