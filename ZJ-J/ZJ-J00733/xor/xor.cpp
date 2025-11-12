#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,f[500005][2],opt[500005][2];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		f[i][i&1]=a[i]==k;
	}
	for(int i1=1,j=0;i1<=n,j<n;){
		j++;
//		cout<<"opt[i1][(j-1)&1]^a[j]:"<<(opt[i1][(j-1)&1]^a[j])<<"\n";
		if((opt[i1][(j-1)&1]^a[j])==k||a[j]==k){/*cout<<i1<<" "<<j<<endl;*/f[i1][j&1]=f[i1][(j-1)&1]+1,i1=j,ans++;}
		else f[i1][j&1]=f[i1][(j-1)&1],opt[i1][j&1]=opt[i1][(j-1)&1]^a[j];
	}
	cout<<ans;
}
