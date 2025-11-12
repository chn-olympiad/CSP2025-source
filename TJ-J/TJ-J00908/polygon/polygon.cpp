#include<cstdio>
#include<algorithm>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n,mx=0,cnt=0,ans=0;
	scanf("%d",&n);	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(a[i],mx);
		cnt+=a[i];
	}
	if(n<3){
		printf("0");
	}
	else if(n==3){

		if(cnt<=mx*2){
			printf("0");
		}
		else{
			printf("1");
		}
	}
	else{
		unsigned long long int nn=1;
		for(int i=1;i<=n;i++){
			nn=(nn*i);
		}
		int mm=nn/6;;
		for(int i=3;i<=n;i++){
			mm/=i;
			ans+=nn/(i*(nn-mm))%998244353;  
		}
		printf("%d",ans);
	}
	
	return 0;
}
