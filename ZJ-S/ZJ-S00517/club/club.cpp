#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int x,y,z,xx,yy,zz,q,id,q1,q2,q3;
}a[1001000];
int i,n,T,f[210][210][210],j,k,ans,sum,cnt1,cnt2,cnt3,t;
bool cmp1(Node a,Node b){
	return a.q1>b.q1;
}
bool cmp2(Node a,Node b){
	return a.q2>b.q2;
}
bool cmp3(Node a,Node b){
	return a.q3>b.q3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		sum=cnt1=cnt2=cnt3=0;
		for (i=1;i<=n;i++){
		  scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		  t=max(a[i].x,max(a[i].y,a[i].z));
		  if (t==a[i].x) a[i].id=1,a[i].q1=t-max(a[i].y,a[i].z),cnt1++,a[i].q2=a[i].q3=0;
		  else if (t==a[i].y) a[i].id=2,a[i].q2=t-max(a[i].x,a[i].z),cnt2++,a[i].q1=a[i].q3=0;
		  else a[i].id=3,a[i].q3=t-max(a[i].x,a[i].y),cnt3++,a[i].q2=a[i].q1=0;
		  	}
		if (cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			for (i=1;i<=n;i++)
			  sum+=max(a[i].x,max(a[i].y,a[i].z));
			printf("%lld\n",sum);
			continue;
		}
		if (cnt1>n/2){
			sort(a+1,a+n+1,cmp1);
			for (i=1;i<=n/2;i++)
			  sum+=a[i].x;
			for (i=n/2+1;i<=n;i++)
			  sum+=max(a[i].y,a[i].z);
			printf("%lld\n",sum);
			continue;			  
		}
		if (cnt2>n/2){
			sort(a+1,a+n+1,cmp2);
			for (i=1;i<=n/2;i++)
			  sum+=a[i].y;
			for (i=n/2+1;i<=n;i++)
			  sum+=max(a[i].x,a[i].z);
			printf("%lld\n",sum);
			continue;			  
		}
		if (cnt3>n/2){
			sort(a+1,a+n+1,cmp3);
			for (i=1;i<=n/2;i++)
			  sum+=a[i].z;
			for (i=n/2+1;i<=n;i++)
			  sum+=max(a[i].x,a[i].y);
			printf("%lld\n",sum);
			continue;			  
		}
/*		for (i=1;i<=3;i++)
		  c[i]=0;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++){
			if (c[a[i].id]==n/2) {
				t=i;
				break;
		}
			sum+=a[i].q;
			c[a[i].id]+=1;
		}
		for (i=t;i<=n;i++)
		  sum+=max(a[i].xx,max(a[i].yy,a[i].zz));
		*/
	/*	if (n<=200){
			for (i=0;i<=200;i++){
				for (j=0;j<=200;j++)
				  for (k=0;k<=200;k++)
				    f[i][j][k]=0;
			}
			
			ans=0;
			for (i=1;i<=n;i++)
				for (j=0;j<=i;j++)
				  for (k=0;k<=i;k++){
				  	if (i==1){
				  		f[1][1][0]=a[1].x;
				  		f[1][0][1]=a[1].y;
				  		f[1][0][0]=a[1].z;
				  		continue;
					  }
				    if (j>n/2||k>n/2||(i-j-k)>n/2||j+k>i) break;
				   if (j>0) f[i][j][k]=max(f[i-1][j-1][k]+a[i].x,f[i][j][k]);
				  if (k>0)  f[i][j][k]=max(f[i-1][j][k-1]+a[i].y,f[i][j][k]);
				    f[i][j][k]=max(f[i-1][j][k]+a[i].z,f[i][j][k]);	
					ans=max(ans,f[i][j][k]);		    
			}		
				for (j=0;j<=200;j++)
				  for (k=0;k<=200;k++)
				   	ans=max(ans,f[n][j][k]);
			printf("%lld\n",ans);
		}*/
	}
}