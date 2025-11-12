#include <bits/stdc++.h>
using namespace std;
int n,k,i,a[500010],j,sum,b[500010],f[500010];
bool pd(int t,int w){
	int i;
	for(i=t;i<=w;i++)
		if(f[i]) return 0;
	return 1;
}
void ok(int t,int w){
	int i;
	for(i=t;i<=w;i++) f[i]=1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;b[0]=sum=0;memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)f[i]=1,sum++;
	}
	for(i=2;i<=n;i++)
		for(j=1;j<=n-i+1;j++)
			if(pd(j,j+i-1)&&(b[j+i-1]^b[j-1])==k){
				ok(j,j+i-1);j=j+i-1;sum++;
			}
	cout<<sum;
	return 0;
}