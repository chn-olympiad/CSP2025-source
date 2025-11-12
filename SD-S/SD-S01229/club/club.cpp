#include<bits/stdc++.h>
using namespace std;
struct node1{
	int a1,a2,a3;
	int d;
}a[100001];
struct node2{
	int a1,a2,a3;
}d1[100001],d2[100001],d3[100001];
bool cmp1(node2 x,node2 y){
	return min((x.a1-x.a2),(x.a1-x.a3))<min((y.a1-y.a2),(y.a1-y.a3));
}
bool cmp2(node2 x,node2 y){
	return min((x.a2-x.a1),(x.a2-x.a3))<min((y.a2-y.a1),(y.a2-y.a3));
}
bool cmp3(node2 x,node2 y){
	return min((x.a3-x.a1),(x.a3-x.a2))<min((y.a3-y.a1),(y.a3-y.a2));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	int num1,num2,num3;
	int numd1,numd2,numd3;
	int ans;
	while(t--){
		scanf("%d",&n);
		num1=num2=num3=0;
		numd1=numd2=numd3=1;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				a[i].d=1;
				num1++;
				d1[numd1].a1=a[i].a1;
				d1[numd1].a2=a[i].a2;
				d1[numd1].a3=a[i].a3;
				numd1++;
				ans+=a[i].a1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				a[i].d=2;
				num2++;
				d2[numd2].a1=a[i].a1;
				d2[numd2].a2=a[i].a2;
				d2[numd2].a3=a[i].a3;
				numd2++;
				ans+=a[i].a2;
			}
			else{
				a[i].d=3;
				num3++;
				d3[numd3].a1=a[i].a1;
				d3[numd3].a2=a[i].a2;
				d3[numd3].a3=a[i].a3;
				numd3++;
				ans+=a[i].a3;
			}
		}
		if(num1<=n/2&&num2<=n/2&&num3<=n/2){
			printf("%d\n",ans);
		}
		else{
			if(num1>n/2){
				sort(d1+1,d1+numd1,cmp1);
				for(int i=1;i<=numd1-1;i++){
					if(num1<=n/2){
						break;
					}
					num1--;
					ans-=d1[i].a1;
					ans+=max(d1[i].a2,d1[i].a3);
				}
			}
			else if(num2>n/2){
				sort(d2+1,d2+numd2,cmp2);
				for(int i=1;i<=numd2-1;i++){
					if(num2<=n/2){
						break;
					}
					num2--;
					ans-=d2[i].a2;
					ans+=max(d2[i].a1,d2[i].a3);
				}
			}
			else{
				sort(d3+1,d3+numd3,cmp3);
				for(int i=1;i<=numd3-1;i++){
					if(num3<=n/2){
						break;
					}
					num3--;
					ans-=d3[i].a3;
					ans+=max(d3[i].a1,d3[i].a2);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

