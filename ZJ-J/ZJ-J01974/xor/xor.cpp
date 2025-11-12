#include<bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;
//bool kkksc03;
const int mxn=500001;
ll n,k,a[mxn],ans=0,b[mxn]={};
//bool soha;
inline ll read(){
    ll x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
int main(){
	//printf("%lfMB\n",(&soha-&kkksc03)/1024.0/1024.0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	n=read();k=read();
	for(rint i=1;i<=n;i++)a[i]=read();
	b[1]=a[1];
	for(rint i=2;i<=n;i++)b[i]=b[i-1]^a[i];
	int last=1;
	for(rint i=1;i<=n;i++){
		for(rint j=last;j<=i;j++){
			if((j==1?b[i]:b[i]^b[j-1])==k){
				ans++;last=i+1;break;
			}
		}
	}
	cout<<ans;
    return 0;
}
/*
    Code is far away from
bug with the animal protecting
    神兽保佑，代码无bug
*/
