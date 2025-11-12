#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,x,y,z,sum1,sum2,a[N][5],b[N],n,dy;
int s1,s2,s3,t1[N],t2[N],t3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;sum1=sum2=s1=s2=s3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				a[i][1]=x;s1++;t1[s1]=i;
				if(y>=z)a[i][2]=y,a[i][3]=z;
				else a[i][2]=z,a[i][3]=y;
			}
			else if(y>=x&&y>=z){
				a[i][1]=y;s2++;t2[s2]=i;
				if(x>=z)a[i][2]=x,a[i][3]=z;
				else a[i][2]=z,a[i][3]=x;
			}
			else{
				a[i][1]=z;s3++;t3[s3]=i;
				if(x>=y)a[i][2]=x,a[i][3]=y;
				else a[i][2]=y,a[i][3]=x;
			}
		}
		for(int i=1;i<=n;i++)sum1+=a[i][1];
		if(s1>n/2){
			dy=s1-n/2;
			for(int i=1;i<=s1;i++)
				b[i]=a[t1[i]][1]-a[t1[i]][2];
			sort(b+1,b+1+s1);
			for(int i=1;i<=dy;i++)sum2+=b[i];
		}
		if(s2>n/2){
			dy=s2-n/2;
			for(int i=1;i<=s2;i++)
				b[i]=a[t2[i]][1]-a[t2[i]][2];
			sort(b+1,b+1+s2);
			for(int i=1;i<=dy;i++)sum2+=b[i];
		}
		if(s3>n/2){
			dy=s3-n/2;
			for(int i=1;i<=s3;i++)
				b[i]=a[t3[i]][1]-a[t3[i]][2];
			sort(b+1,b+1+s3);
			for(int i=1;i<=dy;i++)sum2+=b[i];
		}
		cout<<sum1-sum2<<"\n";
	}
	return 0;
}
