#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mx=1e5+10;
int t,n,a[mx][4],ans,w[mx],d[mx],s,q,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(w,0,sizeof(w));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		s=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(d[j]<=s){
					q=w[i];
					w[i]=max(w[i-1]+a[i][j],w[i]);
					if(w[i]!=q) c=j;
				}
			}
			d[c]++;	
		}
		printf("%d\n",w[n]);
	}
	return 0;
}