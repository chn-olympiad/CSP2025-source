#include<bits/stdc++.h>
using namespace std;
bool f(long long int a,long long int b){
	if(a<b){
		return a>b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int t,n,a[10005][8],b[2005],c[2005],as[2005],bs[2005],cs[2005];
	scanf("%lld",&t);
	while(t--){
		long long int a1=0,a2=0,a3=0,ans=0;
		long long int max1=0,ah=1,bh=1,ch=1;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			max1=max(max(a[i][1],a[i][2]),a[i][3]);
			if(max1==a[i][1]){
				a1++;
				ans+=a[i][1];
				b[i]=a[i][2]-a[i][1];
				c[i]=a[i][3]-a[i][1];
				as[ah]=max(b[i],c[i]);
				ah++;
			}else if(max1==a[i][2]){
				a2++;
				ans+=a[i][2];
				b[i]=a[i][1]-a[i][2];
				c[i]=a[i][3]-a[i][2];
				bs[bh]=max(b[i],c[i]);
				bh++;
			}else if(max1==a[i][3]){
				a3++;
				ans+=a[i][3];
				b[i]=a[i][1]-a[i][3];
				c[i]=a[i][2]-a[i][3];
				cs[ch]=max(b[i],c[i]);
				ch++;
			}
		}
		if(a1>n/2){
			sort(as+1,as+ah+1,f);
			for(int i=1;i<=a1-(n/2);i++){
				ans+=as[i];
			}
			printf("%lld",ans);
		}else if(a2>n/2){
			sort(bs+1,bs+bh+1,f);
			for(int i=1;i<=a2-(n/2);i++){
				ans+=bs[i];
			}
			printf("%lld",ans);
		}else if(a3>n/2){
			sort(cs+1,cs+ch+1,f);
			for(int i=1;i<=a3-(n/2);i++){
				ans+=cs[i];
			}
			printf("%lld",ans);
		}else{
			printf("%lld",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
