#include<bits/stdc++.h>
using namespace std;
int a[500001],k,n,sum,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
			continue;
		}
		cnt=a[i];
		for(int j=i+1;j<=n&&a[j]!=k;j++){
			cnt=cnt^a[j];
			if(cnt==k){
				sum++;
				cnt=a[j+1];
				i=j+1;
				break;
			}
		}
	}
	printf("%d",sum);
}
