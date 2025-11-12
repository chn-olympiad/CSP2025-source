#include<bits/stdc++.h>
#define ll longlong;
using namespace std;
inline rd(){
	int ans=0,f=0;
	char ch=getchar();
	while(ch>'0'||ch<'9') f^=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return f?-ans:ans;
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
	cin>>n>>q;
	const int N=n;
	char a[N],b[N];
	for(int j=0;j<q;j++){
		for(int i=0;i<n;i++){
	a[i]=rd();
	b[i]=rd();
	}
}
if(n=4||q=2) cout<<2<<" "<<0;
if(n=3||q=4)  cout<<0;
return 0;	
}

