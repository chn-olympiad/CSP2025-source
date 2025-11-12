// 曹佳琦 SN-S00300 西安市庆华中学 
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int b1,b2,b3;
int ans1,ans2;
int sum[10010];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
	int a[10010],b[10010],c[10010];
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>=c[j]&&b1<n/2){
				ans1+=a[j];
				b1++;
			}
			if(b[j]>=a[j]&&b[j]>=c[j]&&b2<n/2){
				ans1+=b[j];
				b2++;
			}
			if(c[j]>=b[j]&&c[j]>=a[j]&&b3<n/2){
				ans1+=c[j];
				b3++;
			}
			if(a[j]>=b[j]&&a[j]>=c[j]) sum[j]=a[j];
			else if(b[j]>=a[j]&&b[j]>=c[j]) sum[j]=b[j];
			else if(c[j]>=b[j]&&c[j]>=a[j]) sum[j]=c[j];
		}
		b1=0;
		b2=0;
		b3=0;
		int no=0;
		for(int j=n-1;j>=0;j--){
			int c1=b1,c2=b2,c3=b3;
			if(a[j]>=b[j]&&a[j]>=c[j]&&b1<n/2){
				ans2+=a[j];
				b1++;
			}
			if(b[j]>=a[j]&&b[j]>=c[j]&&b2<n/2){
				ans2+=b[j];
				b2++;
			}
			if(c[j]>=b[j]&&c[j]>=a[j]&&b3<n/2){
				ans2+=c[j];
				b3++;
			}
			if(c1==b1&&c2==b2&&c3==b3&&b1<n/2){
				ans2+=a[j];
				b1++;
			}
			else if(c1==b1&&c2==b2&&c3==b3&&b2<n/2){
				ans2+=b[j];
				b2++;
			}
			else if(c1==b1&&c2==b2&&c3==b3&&b3<n/2){
				ans2+=c[j];
				b3++;
			}
		}
		if(ans1>ans2) cout<<ans1<<endl;
		else cout<<ans2<<endl;
		ans1=0;
		ans2=0;
		b1=0;
		b2=0;
		b3=0;
	}
	return 0;
}

