#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;
const long long maxn=1e5+10;
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
long long a[maxn][3],n,f[3][maxn],b[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,ans,o,p;
	t=read();
	while(t--){
		ans=0;
		n=read();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(long long i=1;i<=n;i++){
			o=0,p=0;
			for(long long j=0;j<3;j++){
				a[i][j]=read();
				if(a[i][j]>o){
					o=a[i][j];
					p=j;
				}
			}
			f[p][0]++;
			f[p][f[p][0]]=i;
			ans+=o;
		}
		long long fl=1;
		p=0;
		for(long long i=0;i<3;i++){
			if(f[i][0]*2>n){
				fl=0;
				p=i;
			}
		}
		if(fl==0){
			for(long long i=1;i<=f[p][0];i++){
				b[i]=a[f[p][i]][p]-max(a[f[p][i]][(p+1)%3],a[f[p][i]][(p+2)%3]);
			}
			sort(b+1,b+f[p][0]+1);
			for(long long i=1;i<=f[p][0]-n/2;i++){
				ans-=b[i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
