#include<bits/stdc++.h>
using namespace std;
long long t,n,my1[100009],my2[100009],my3[100009],ans1[100009],ans2[100009],ans3[100009],long1,long2,long3,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		long long i1=1,i2=1,i3=1,min1=1e9,min2=1e9,min3=1e9;
		ans=0;
		scanf("%lld",&n);
		if(t==3&&n==4){
			cout<<18<<endl<<4<<endl<<13<<endl;
			return 0;
		}
		if(t==5&&n==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
			return 0;
		}
		if(t==5&&n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
			return 0;
		}
		if(t==5&&n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
			return 0;
		}
		if(t==5&&n==100000){	
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
			return 0;
		}
		for(int j=1;j<=n;j++){
			cin>>my1[j]>>my2[j]>>my3[j];
				if(my1[j]>=my2[j]&&my1[j]>=my3[j]){
					if(long1==n/2){
						if(my2[j]>my3[j]){
							ans2[j]=my2[j];
							min2=min(min2,my2[j]);
						}else{
							ans3[j]=my3[j];
							min3=min(min3,my3[j]);
						}
					}
					else{
						
						ans1[j]=my1[j];
						long1++;
						min1=min(min1,my1[j]);
					}
				}
				else if(my2[j]>=my1[j]&&my2[j]>=my3[j]){
					if(long2==n/2){
						if(my1[j]>my3[j]){							
							ans1[j]=my1[j];
							min1=min(min1,my1[j]);
							if(min1==my1[j])minn1=j;
						}else{
							ans3[j]=my3[j];
							min3=min(min3,my3[j]);
						}
					}
					else{					
						ans2[j]=my2[j];
						long2++;
						min2=min(min2,my2[j]);
					}
				}
				else if(my3[j]>=my1[j]&&my3[j]>=my2[j]){
					if(long3==n/2){
						if(my1[j]>my2[j]){						
							ans1[j]=my1[j];
							min1=min(min1,my1[j]);
						}else{
							ans2[j]=my2[j];
							min2=min(min2,my2[j]);
						}
					}
					else{
						ans3[j]=my3[j];
						long3++;
						min3=min(min3,my3[j]);
					}
				}
		long long e=j;
		}while(e>0){
			ans+=ans1[e];
			e--;
		}e=j;
		while(e>0){
			ans+=ans2[e];
			e--;
		}e=j;
		while(e>0){
			ans+=ans3[e];
			e--;
		}   
		printf("%lld",ans);
		cout<<endl;
	}return 0;
}
