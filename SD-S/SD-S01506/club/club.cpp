#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
long long n,a[13][N],tot[13];
long long cal(long long t1,long long t2,long long t3){
	if(t1>=t2&&t1>=t3){
		if(t2>=t3){
			return 12;
		}
		else{
			return 13;
		}
	}
	if(t2>=t1&&t2>=t3){
		if(t1>=t3){
			return 21;
		}
		else{
			return 23;
		}
	}
	if(t3>=t2&&t3>=t1){
		if(t1>=t2){
			return 31;
		}
		else{
			return 32;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long sum=0;
		cin>>n;
		tot[1]=tot[2]=tot[3]=0;
		for(int i=1;i<=n;++i){
			long long x[13];
			scanf("%lld %lld %lld",&x[1],&x[2],&x[3]);
			long long t=cal(x[1],x[2],x[3]);
			a[t/10][++tot[t/10]]=x[t/10]-x[t%10];
			sum+=x[t/10];
		}
		for(int i=1;i<=3;++i){
			if(tot[i]>n/2){
				sort(a[i]+1,a[i]+1+tot[i]);
				for(int j=1;j<=tot[i]-n/2;++j){
					sum-=a[i][j];
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
15:00 100pts
*/
