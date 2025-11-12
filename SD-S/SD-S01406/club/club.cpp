#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long sum,maxn;
long long w1,w2,w3;
long long x,y,z;
long long a[10005][3];
long long ma[10005];
bool flag[10005]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cin>>t;
	scanf("%lld",&t);
	while(t--){
		//cin>>n;
		scanf("%lld",&n);
		 w1=w2=w3=n/2;
		for(int i=1;i<=n;i++){
			//cin>>x>>y>>z;
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i][0]=x;
			a[i][1]=y;
			a[i][2]=z;
		maxn=max(max(x,y),z);
		ma[i]=maxn;
		if(maxn==x){
			w1--;
			if(w1<0){
				for(int j=1;j<=i;j++){
					int maxn2=max(a[j][1],a[j][2]);
				if(maxn2+x>ma[j]&&flag[i]==0){
					sum-=a[j][0];
					sum+=(maxn2+x);
					w1++; 
					flag[i]=1;
				}
				}
			}else sum+=maxn;
		}
		if(maxn==y){
			w2--;
			if(w2<0){
				for(int j=1;j<=i;j++){
					int maxn2=max(a[j][0],a[j][2]);
				if(maxn2+y>ma[j]&&flag[i]==0){
					sum=sum-a[j][1];
					sum+=(maxn2+y);
					w2++;
					flag[i]=1;
			}
				}
				
		}else sum+=maxn;
	}
		if(maxn==z){
			w3--;
			if(w3<0){
				for(int j=1;j<=i;j++){
					int maxn2=max(a[j][1],a[j][0]);
				if(maxn2+z>ma[j]&&flag[i]==0){
					sum=sum-a[j][2];
					sum+=(maxn2+z);
				w3++;
				flag[i]=1;
				}
				
			}
		}else sum+=maxn;
	}
}
printf("%lld\n",sum);
	//	cout<<sum<<"\n";		
			sum=0;
	//Ren5Jie4Di4Ling5%
}
	return 0;
} 
