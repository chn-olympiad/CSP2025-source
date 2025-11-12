#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int x1;
	int x2;
	int x3;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int c1=0,c2=0,c3=0,ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
		}
		for (int i=1;i<=n;i++){
			if (a[i].x1>a[i].x2&&a[i].x1>a[i].x3){
				if (c1+1<=n/2){
					c1++;
					ans+=a[i].x1;
				}else{
					a[i].x1=0;
				}
			}
			if (a[i].x2>a[i].x1&&a[i].x2>a[i].x3){
				if (c2+1<=n/2){
					c2++;
					ans+=a[i].x2;
				}else{
					a[i].x2=0;
				}
			}
			if (a[i].x3>a[i].x1&&a[i].x3>a[i].x2){
				if (c3+1<=n/2){
					c3++;
					ans+=a[i].x3;
				}else{
					a[i].x3=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
