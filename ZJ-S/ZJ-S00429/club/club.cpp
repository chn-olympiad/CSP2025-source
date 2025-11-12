#include<bits/stdc++.h>
using namespace std;
int T, n, b[10], l1, l2, l3, ans;
struct node{
	int x, y, z, ab;
}a[100010];
bool cmp(node x, node y){
	return x.ab>y.ab;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;l1=0;l2=0;l3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				scanf("%d",&b[i]);
			a[i].x=b[1];a[i].y=b[2];a[i].z=b[3];
			sort(b+1,b+4);
			a[i].ab=b[3]-b[2];
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
		//	cout<<a[i].x<<" "<<a[i].y<<a[i].z<<endl;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(l1!=n/2)l1++,ans+=a[i].x;
				else{
					if(a[i].y>=a[i].z){
						l2++;
						ans+=a[i].y;
					}
					else{
						l3++;
						ans+=a[i].z;
					}
				}
				continue;
			}
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(l2!=n/2)l2++,ans+=a[i].y;
				else{
					if(a[i].x>=a[i].z){
						l1++;
						ans+=a[i].x;
					}
					else{
						l3++;
						ans+=a[i].z;
					}
				}
				continue;
			}
			if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				if(l3!=n/2)l3++,ans+=a[i].z;
				else{
					if(a[i].y>=a[i].x){
						l2++;
						ans+=a[i].y;
					}
					else{
						l1++;
						ans+=a[i].x;
					}
				}
				continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}