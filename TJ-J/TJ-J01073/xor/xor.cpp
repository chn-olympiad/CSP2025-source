#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
int sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			int ans=a[j];
			for(int q=1;q<=i;q++){
				ans^=a[j+q-1];
					
			}
			if(ans==k){
				sum++;
			}
		}
	}
	printf("%d",sum);
}









