#include<cstdio>
#include<algorithm>
int n,k,maxx=0;
int a[500012];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int s=0,c=0;
		for(int j=i;j<=n;j++){
			s^=a[j];
			if(s==k){
				c++;
				s=0;
			}
			if(s>k){
				s=0;
			}
		}
		if(c>maxx)maxx=c;
	}
	printf("%d\n",maxx);
	return 0;
}
