#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],d[N];
int xo(int x,int y){
	int t;
	if((x+y==2)||(x+y==0)) t=0;
	else t=1;
	return t;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k,m,ans=0;//1 xor 1 = 0 , 1 xor 0 = 1
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m=xo(a[j],a[j-1]);
			if(m==k) ans++;
   			a[j]=m;
		}
		for(int j=1;j<=n;j++){
			a[j]=d[j];
		}
	}
	cout<<ans;
	return 0;
}