#include<iostream>
using namespace std;
int t,n,a[100010],b[100010],c[100010],x=0,y=0,z=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int l=n/2,cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		 if(a[i]>=b[i]&&a[i]>=c[i]){
				x++;
				cnt+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				y++;
				cnt+=b[i];
			}else{
				z++;
				cnt+=c[i];
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

