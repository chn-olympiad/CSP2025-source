#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[500010],cnt=0,sum=0,ans=0,flag=0;
//struct str{
//	int l,r,x,flag=0;
//}b[500010];
//int cmp(str a,str b){
//	if(a.r<b.r){
//		return 1;
//	}
//	return 0;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(n%2==0){
			cout<<n/2;
		}else if(n%2==1){
			cout<<(n-1)/2;
		}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(i==j){
//				f[cnt]=a[i];
//				if(f[cnt]==m){
//					b[sum].l=i;b[sum].r=j;
//					sum++;
//				}
//			}else{
//				f[cnt]=0;
//				for(int k=i;k<=j;k++){
//					f[cnt]^=a[k];
//				}
//				if(f[cnt]==m){
//					b[sum].l=i;b[sum].r=j;
//					sum++;
//				}
//				cnt++;
//			}
//		}
//	}
//	cnt--;
//	for(int i=1;i<=sum;i++){
//		b[i].x=b[i].r-b[i].l;
//	}
//	sort(b+1,b+sum+1,cmp);
//	for(int i=1;i<=sum;i++){
//		if(b[i].flag==0){
//			maxn++;
//			b[i].flag=1;
//			for(int j=1;j<=sum;j++){
//				if(b[j].l>b[i].r&&b[j].flag==0){
//					maxn++;
//				}
//			}
//		}
//		for(int j=1;j<=sum;j++){
//			b[j].flag=0;
//		}
//		ans=max(ans,maxn);
//	}
//	cout<<ans;
	return 0;
}
