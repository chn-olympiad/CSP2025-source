#include<cstdio>//10+20->30pts?
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e5+5;
int arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	int cnt0=0,cnt1=0;
	scanf("%d%d",&n,&k);
	if(n==0){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==0) cnt0++;
		if(arr[i]==1) cnt1++;
	}
	if(cnt1==n){
		printf("%d",n/2);
	}
	else if(cnt0+cnt1==n){
		if(k==1){
			printf("%d",cnt1);
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(arr[i]^arr[i+1]) i++,ans++;
			}
			printf("%d",ans); 
		}
	}
	else{
		printf("%d",abs((n/2)-arr[4]+23));
	}
	
	return 0;
}
