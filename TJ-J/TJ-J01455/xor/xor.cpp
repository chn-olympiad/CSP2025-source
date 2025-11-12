#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,a[1005],f[105][105],ans=0;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	memset(f,0,sizeof(f));
	f[1][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=f[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==k){
				ans++;
				i=i+j-1;
				break;
			}
		}
	}
	printf("%lld",ans);


	fclose(stdin);
	fclose(stdout);
	return 0;
}
