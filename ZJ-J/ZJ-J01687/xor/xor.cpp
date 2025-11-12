#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],b[N],c[N][N];
int n,m,k,ans;
inline int read(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline int fun(int l,int r){
	int res=0;
	while(l<=r){
		int j=l,tmp=a[l];
		while(j<=r){
			j++;
			if(tmp==m){
				if(c[j][r]==0) c[j][r]=fun(j,r);
				res=max(res,c[j][r]+1);
			}
			if(j>r) break;
			tmp^=a[j];
		}
		l++;
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==m) b[++k]=i,ans++;
	}
	b[++k]=n+1;
	for(int z=1;z<=k;z++){
		int l=b[z-1]+1,r=b[z]-1;
		if(c[l][r]==0) c[l][r]=fun(l,r);
		ans+=c[l][r];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
