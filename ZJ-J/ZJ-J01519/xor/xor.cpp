#include<bits/stdc++.h>
using namespace std;
//60pts
const int N=2e5+5;
long long a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if(n<=1000){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]^a[i];
		}
//		for(int i=1;i<=n;i++){
//			cout<<sum[i]<<" ";
//		}
//		cout<<endl;
		int l=1,r=1,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=l;j<=r;j++){
				if(j>i)break;
				if(k==(sum[i]^sum[j-1])){
					ans++;
//					cout<<i<<" "<<j<<" "<<(sum[i]^sum[j-1])<<endl;
					l=i+1;
					r=i+1;
					break;
				}
			}
			r++;
		}
		printf("%d",ans);
	}
	else{
		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>1)flag=false;
		}
		if(flag){
			int ans=0;
			if(k){
				for(int i=1;i<=n;i++)if(a[i])ans++;
				printf("%d",ans);
			}
			else{
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i])cnt++;
					if(!a[i]){
						ans++;
						cnt=0;
					}
					if(cnt==2){
						ans++;
						cnt=0;
					}
				}
				printf("%d",ans);
			}
		}
		else printf("0");
	}
	return 0;
}
