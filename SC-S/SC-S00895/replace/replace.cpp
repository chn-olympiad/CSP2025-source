#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,q,jsa,jsb,pd1,c[1010];
string a[1010],b[1010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string A,B;
		cin>>A>>B;
		for(int j=1;j<=n;j++){
			for(int k=0;k+a[j].size()-1<A.size();k++){
				int pd=0;
				for(int z=0;z<a[i].size();i++){
					if(a[j][z]!=A[k+z]){
						pd=1;
					}
				}
				if(pd==0){
					for(int z=k;z<=k+a[j].size()-1;z++){
						
					}
				}
			}
		}
	}
	//再见，OI
	return 0;
}