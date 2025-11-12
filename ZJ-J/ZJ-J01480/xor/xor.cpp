#include<bits/stdc++.h>
using namespace std;
#define maxn 514514
int a[maxn],k,n;
int b[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i])ans++;
		}
	}
	printf("%d",ans);
}