#include<bits/stdc++.h>
using namespace std;

int n,k,x[1010][1010],f[1010],a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=-1;
	if(n>1000){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(!a[i])
					ans++;
				else if(a[i-1]==a[i]){
					i++;
					ans++;
				}
			}
			printf("%d\n",ans);
		}else{
			int ans=0;
			for(int i=2;i<=n;i++)
				if(a[i]^a[i-1]==k){
					ans++;
					i++;
				}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		x[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
			x[i][j]=x[i][j-1]^a[j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=max(f[i],f[j-1]+(x[j][i]==k));
	printf("%d\n",f[n]);
	return 0;
}
