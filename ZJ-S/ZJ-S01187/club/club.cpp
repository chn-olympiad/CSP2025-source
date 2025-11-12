#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ggg{
	int x,y,z;
}a[100005];
bool cmp(ggg a,ggg b){
	return (a.x+a.y+a.z)<(b.x+b.y+b.z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int xx=0,yy=0,zz=0,ans=0,ans1=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+n+1,cmp);
		if(a[1].y==0&&a[1].z==0&&a[2].y==0&&a[2].z==0&&a[3].y==0&&a[3].z==0){
			for(int i=n;i>=n/2;i--)ans+=a[i].x;
			printf("%d\n",ans);continue;
		}
		for(int i=1;i<=n;i++){
			int num[4]={0,a[i].x,a[i].y,a[i].z};
			sort(num+1,num+4);
			for(int j=3;j>=1;j--){
				if(num[j]==a[i].x&&xx<n/2){
					xx++,ans+=a[i].x;break;
				}
				if(num[j]==a[i].y&&yy<n/2){
					yy++,ans+=a[i].y;break;
				}
				if(num[j]==a[i].z&&zz<n/2){
					zz++,ans+=a[i].z;break;
				}
			}
		}printf("%d\n",ans);
	}
	return 0;
}//Ren5Jie4Di4Ling5%
//RP++

