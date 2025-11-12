#include<iostream>
#include<algorithm>
using namespace std;
int t,n,n1,n2,n0,s;
struct stu{
	int m1,m2,m0;
};
bool cmp(stu a, stu b){
	if(abs(a.m1-a.m0)!=abs(b.m1-b.m0))return abs(a.m1-a.m0)>abs(b.m1-b.m0);
	return abs(a.m2-a.m0)>=abs(b.m2-b.m0);
}
stu a[100007];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s=0;
		scanf("%d",&n);
		n1=0;
		n2=0;
		n0=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].m0,&a[i].m1,&a[i].m2);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(n0<n/2&&a[i].m0>=a[i].m1){
				n0++;
				s+=a[i].m0;
			}else if(n1<n/2&&a[i].m1>=a[i].m2){
				n1++;
				s+=a[i].m1;
			}else{
				n2++;
				s+=a[i].m2;
			}
//			printf("%d %d %d\n",a[i].m0,a[i].m1,a[i].m2);
		}
		printf("%d\n",s);
	}
	
	return 0;
}
