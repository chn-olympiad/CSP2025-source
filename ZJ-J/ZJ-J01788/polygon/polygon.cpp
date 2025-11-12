#include<bits/stdc++.h>
using namespace std;
int a[5050];
long long p;
int n,bian=3,max=1;
long long ans=0;
bool cmp(int x,int y){
	return x>y;
}
bool t(int x){
	int o=0;
	while(x!=0){
		if(x%2==1) o++;
		x=(x>>1);
	}
	return o<3;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==1){
		cout<<(1<<n)-n*(n-1)/2-n-1;
		return 0;
	}
	int max=-1,j,k,s;
	for(int i=7;i<(1<<n);i++){
		if(t(i)) continue;
		j=i;
		k=0;
		s=1;
		max=-1;
		while(j!=0){
			if(j%2==1){
				k=k+a[s];
				if(max<=a[s]) max=a[s];	
			} 
			j=(j>>1);
			s++;
		}
		if(k>(max<<1)) {
			ans++;
			ans=ans%998244353;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
