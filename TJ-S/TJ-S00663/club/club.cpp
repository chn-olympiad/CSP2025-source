#include<bits/stdc++.h>

using namespace std;


long long t,n,a[100001][3],ans,b[3],cc,dd,ee;

struct stu{
	int x,y,z;
};
stu e[100001],c[100001],d[100001];
int cmp(stu a,stu b)
{
	return a.x-a.y<b.x-b.y or a.x-a.y<b.x-b.z or a.x-a.z<b.x-b.y or a.x-a.z<b.x-b.z;
}
int cmpp(stu a,stu b)
{
	return a.y-a.x<b.y-b.x or a.y-a.x<b.y-b.z or a.y-a.z<b.y-b.x or a.y-a.z<b.y-b.z;
}
int cmppp(stu a,stu b)
{
	return a.z-a.y<b.z-b.y or a.z-a.y<b.z-b.x or a.z-a.x<b.z-b.y or a.z-a.x<b.z-b.x;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		b[0]=0;
		b[1]=0;
		b[2]=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]>a[j][1] and a[j][0]>a[j][2]){
				b[0]++;
				cc++;
				c[cc].x=a[j][0];
				c[cc].y=a[j][1];
				c[cc].z=a[j][2];
				ans+=a[j][0];
			}else if(a[j][1]>a[j][2]){
				b[1]++;
				dd++;
				d[dd].x=a[j][0];
				d[dd].y=a[j][1];
				d[dd].z=a[j][2];
				ans+=a[j][1];
			}else{
				b[2]++;
				ee++;
				e[ee].x=a[j][0];
				e[ee].y=a[j][1];
				e[ee].z=a[j][2];
				ans+=a[j][2];
			}
		}
		long long ccc=1,ddd=1,eee=1;
		while(b[0]>n/2 or b[1]>n/2 or b[2]>n/2){
			sort(c+1,c+1+cc,cmp);
			sort(d+1,d+1+dd,cmpp);
			sort(e+1,e+1+ee,cmppp);
			if(b[0]>n/2){
				
				for(int l=1;l<=b[0]-n/2;l++){
					if(c[ccc].y>c[ccc].z){
						b[1]++;
						ans-=c[ccc].x-c[ccc].y;
						dd++;
						d[dd].x=c[ccc].x;
						d[dd].y=c[ccc].y;
						d[dd].z=c[ccc].z;
						ccc++;
					}else{
						b[2]++;
						ans-=c[ccc].x-c[ccc].z;
						ee++;
						e[ee].x=c[ccc].x;
						e[ee].y=c[ccc].y;
						e[ee].z=c[ccc].z;
						ccc++;
					}
				}
				b[0]=n/2;
			}
			if(b[1]>n/2){
				
				for(int l=1;l<=b[1]-n/2;l++){
					if(d[ddd].x>d[ddd].z){
						b[0]++;
						ans-=d[ddd].y-d[ddd].x;
						cc++;
						c[cc].x=d[ddd].x;
						c[cc].y=d[ddd].y;
						c[cc].z=d[ddd].z;
						ddd++;
					}else{
						b[2]++;
						ans-=d[ddd].y-d[ddd].z;
						ee++;
						e[ee].x=d[ddd].x;
						e[ee].y=d[ddd].y;
						e[ee].z=d[ddd].z;
						ddd++;
					}
				}
				b[1]=n/2;
			}
			if(b[2]>n/2){
				
				for(int l=1;l<=b[2]-n/2;l++){
					if(e[eee].y>c[ccc].x){
						b[1]++;
						ans-=e[eee].z-e[eee].y;
						dd++;
						d[dd].x=e[eee].x;
						d[dd].y=e[eee].y;
						d[dd].z=c[eee].z;
						eee++;
					}else{
						b[0]++;
						ans-=e[eee].z-e[eee].x;
						cc++;
						c[cc].x=e[eee].x;
						c[cc].y=c[eee].y;
						c[cc].z=c[eee].z;
						eee++;
					}
				}
				b[2]=n/2;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
 } 
