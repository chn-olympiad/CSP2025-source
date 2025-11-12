#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],n,k,sum,fa=1,fb=1,l,ans;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]!=1)fa=0;
		if(a[i]!=1&&a[i]!=0)fb=0;
	}if(fa){
		cout<<n/2;
		return 0;
	}if(fb){
		int suma=0,sumb=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1)++suma;
			else ++sumb;
		}
		if(k==1){
			cout<<suma;
		}else cout<<sumb+suma/2;
		return 0;
	}for(int i=1;i<=n;++i)b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j>l;--j){
			int y=b[i]^b[j-1];
			if(y==k){
				++ans;
				l=i;
				break;
			}
		}
	}cout<<ans;
	return 0;
}
