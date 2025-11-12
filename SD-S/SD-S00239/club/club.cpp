#include<bits/stdc++.h>
using namespace std;
struct iii{
	int p1,p2,p3,j1,j,j2;
}a[100100];
long long t,n,ans=0,q1=0,q2=0,q3=0;
iii b[100100],c[100100],d[100100];
bool cmp(iii x,iii y){
	return x.j-x.j1<y.j-y.j1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		q1=0;q2=0;q3=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			a[i].j2=i;
			if(a[i].p1>=a[i].p2&&a[i].p1>=a[i].p3){
				q1++;
				a[i].j=a[i].p1;
				a[i].j1=max(a[i].p2,a[i].p3);
				b[q1]=a[i];
			}else if(a[i].p2>=a[i].p1&&a[i].p2>=a[i].p3){
				q2++;
				a[i].j=a[i].p2;
				a[i].j1=max(a[i].p1,a[i].p3);
				c[q2]=a[i];
			}else{
				q3++;
				a[i].j=a[i].p3;
				a[i].j1=max(a[i].p2,a[i].p1);
				d[q3]=a[i];
			}
		}
		if(q1>n/2){
			sort(b+1,b+q1+1,cmp);
			for(int i=1;i<=q1-n/2;i++){
				a[b[i].j2].j=-1;
			}
		}
		if(q2>n/2){
			sort(c+1,c+q2+1,cmp);
			for(int i=1;i<=q2-n/2;i++){
				a[c[i].j2].j=-1;
			}
		}
		if(q3>n/2){
			sort(d+1,d+q3+1,cmp);
			for(int i=1;i<=q3-n/2;i++){
				a[d[i].j2].j=-1;
			}
		}
		for(long long i=1;i<=n;i++){
			ans+=max(a[i].j,a[i].j1);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
