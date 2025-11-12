#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],ans,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				ans++;
			else{
				t=i;
				while(a[i]==a[i+1])
					++i;
				ans+=(i-t+1)/2;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
