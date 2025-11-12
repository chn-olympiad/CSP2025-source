#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int sum[N]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,temp=0,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		sum[i]=(sum[i-1]^a);
		for(int j=temp;j<i;j++)
			if((sum[i]^sum[j])==k){
				temp=i;
				ans++;
				break;
			}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
