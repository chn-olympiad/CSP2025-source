#include<bits/stdc++.h>
using namespace std;
int n,k,sum=-1,ans=0;
bool f1=1;
int a[100005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(f1){
			f1=0;
			sum=a[i];
			if(a[i]==k){
				ans++;
				f1=1;sum=-1;
			}else if(sum==k){
				ans++;
				f1=1;sum=-1;
			}
			continue;
		}
		if(a[i]==k){
			ans++;
			f1=1;sum=-1;
			continue;
		}
		sum=sum^a[i];
		if(sum==k){
			ans++;
			f1=1;sum=-1;
		}
	}
	printf("%d",ans);
	return 0;
}