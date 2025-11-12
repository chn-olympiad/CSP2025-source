#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a1,a2,a3;
	int cha,maxx,se;
}a[100005];
int cmp(ren x,ren y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			a[i].maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
			int minn=min(a[i].a1,min(a[i].a2,a[i].a3));
			a[i].se=a[i].a1+a[i].a2+a[i].a3-a[i].maxx-minn;
			a[i].cha=a[i].maxx-a[i].se;
		}
		long long ans=0;
		sort(a+1,a+1+n,cmp);
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			if(a[i].maxx==a[i].a1){
				if(num1<n/2){
					num1++;
					ans+=a[i].maxx;
				}else{
					if(a[i].se==a[i].a2)num2++;
					else num3++;
					ans+=a[i].se;
				}
			}
			else if(a[i].maxx==a[i].a2){
				if(num2<n/2){
					num2++;
					ans+=a[i].maxx;
				}else{
					if(a[i].se==a[i].a1)num1++;
					else num3++;
					ans+=a[i].se;
				}
			}
			else if(a[i].maxx==a[i].a3){
				if(num3<n/2){
					num3++;
					ans+=a[i].maxx;
				}else{
					if(a[i].se==a[i].a2)num2++;
					else num1++;
					ans+=a[i].se;
				}
			}
		}
		cout<<ans<<endl;
	}
	
} 
