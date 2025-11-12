#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int k;
int x[4];
int ans=0;
int maxn=-1;
struct node{
	int j1,j2,j3;
	int flag;
}a[100005],choose[100005];
int z[100005];


signed f(int n){
	if(n==1){
		return 1;
	}
	int cnt;
	int sum[4];
	for(int j=1;j<=n/2;j++){
		for(k=1;k<=n;k++){
			if(a[k].j1>maxn&&choose[k].j1==0){
				maxn=a[k].j1;
				cnt=k;
			}
		}
		choose[k].j1=1;
		sum[1]+=maxn;
		maxn=-1;
	}
	for(int j=1;j<=n/2;j++){
		for(k=1;k<=n;k++){
			if(a[k].j2>maxn&&choose[k].j2==0){
				maxn=a[k].j2;
				cnt=k;
			}
		}
		choose[k].j2=1;
		sum[2]+=maxn;
		maxn=-1;
	}
	for(int j=1;j<=n/2;j++){
		for(k=1;k<=n;k++){
			if(a[k].j3>maxn&&choose[k].j3==0){
				maxn=a[k].j3;
				cnt=k;
			}
		}
		choose[k].j3=1;
		sum[3]+=maxn;
		maxn=-1;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]==max(max(sum[1],sum[2]),max(sum[2],sum[3]))){
			ans+=max(max(sum[1],sum[2]),max(sum[2],sum[3]));
			if(i==1){
				//j1
				for(int j=1;j<=n;j++){
					choose[j].j1=1;
					choose[j].j2=0;
					choose[j].j3=0;
				}
			}else if(i==2){
				//j2 
				for(int j=1;j<=n;j++){
					choose[j].j1=0;
					choose[j].j2=1;
					choose[j].j3=0;
				}
			}else if(i==3){
				//j3
				for(int j=1;j<=n;j++){
					choose[j].j1=0;
					choose[j].j2=0;
					choose[j].j3=1;
				}
			}
		}
	}
	n=n/2;
	return n;
}


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].j1>>a[i].j2>>a[i].j3;
		}
		if(n==2){
			z[1]=a[1].j1+a[2].j2;
			z[2]=a[1].j1+a[2].j3;
			z[3]=a[1].j2+a[2].j1;
			z[4]=a[1].j2+a[2].j3;
			z[5]=a[1].j3+a[2].j1;
			z[6]=a[1].j3+a[2].j2;
			for(int i=1;i<=6;i++){
				if(z[i]>maxn)
				{
					maxn=z[i];
				}
			}
			cout<<maxn<<endl;
		}else{
			f(n);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
