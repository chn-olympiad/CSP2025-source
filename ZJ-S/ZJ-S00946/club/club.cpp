#include<bits/stdc++.h>
using namespace std;
struct student{
	long long yy;
	long long idx;
	long long st;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n;
	scanf("%d",&t);
	bool flag[3];
	for(int ii=1;ii<=t;ii++){
		flag[1]=false;flag[0]=false;
		scanf("%d",&n);
		student a[n*3];
		for(int i=0;i<n;i++)
			for(int k=0;k<3;k++){
			scanf("%d",&a[i*3+k].yy);
			a[i*3+k].idx=i;
			a[i*3+k].st=k;
			if(flag[k]==false&&a[i*3+k].yy>0)flag[k]=true;
		}
		long long sum=0;
		if(n<=10){
			int cs=n/2;
			int sum1,sum2;
			for(int i=0;i<pow(3,n);i++)
			{
				sum2=i;sum1=0;
				int l[3];
				memset(l,0,sizeof(l));
				for(int k=0;k<n;k++){
					l[sum2%3]+=1;
					if(l[0]>cs||l[1]>cs||l[2]>cs){
						sum1=0;break;
					}
					sum1+=a[k*3+sum2%3].yy;
				    sum2/=3;
				    
				}
				if(sum1>sum)sum=sum1;
			}
			printf("%d",sum);
			continue;
		}
		student tmp;
		int jh,iii=n*3;
		int ssum[n],tmp1;
		for(int i=0;i<n;i++)
		ssum[i]=a[i*3].yy+a[i*3+1].yy+a[i*3+2].yy;
		while(iii>0){
			jh=0;
			for(int j=0;j<iii-1;j++){
				if(a[j].yy<a[j+1].yy||a[j].yy==a[j+1].yy&&ssum[j]<ssum[j+1]){
					tmp=a[j];tmp1=ssum[j];
					a[j]=a[j+1];ssum[j]=ssum[j+1];
					a[j+1]=tmp;ssum[j+1]=tmp1;
					jh=j+1;
				}
			}
			iii=jh;
		}
		if(flag[0]==0&&flag[1]==0){
			for(int i=0;i<n;i++)
			sum+=a[i].yy;
			printf("%d",sum);
			continue;
		}
		bool use[n];
		long long kk[3];
		kk[0]=n/2;kk[1]=n/2;kk[2]=n/2;
		memset(use,0,sizeof(use));
		long long cnt=0,p=0;
		while(cnt<n){
			if(use[a[p].idx]==0&&kk[a[p].st]>0){
				sum+=a[p].yy;
				use[a[p].idx]=1;
				cnt++;
			}
			else p++;
		}
		printf("%d",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
