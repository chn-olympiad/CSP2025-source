#include<cstdio>
#include<algorithm>
char s[505],n,f;
int a[505],m[505],l;
unsigned long long ans=0llu,k=1llu;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&l);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<n;j++){
			if(a[i]>j)m[j]++;
		}
	}
	for(int j=0;j<n-1;j++){
		for(int i=1;i<=m[j];i++){
		k*=i;k%=998244353;
		}
		ans+=k%998244353;
		ans%=998244353;
	}
	printf("%llu",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
