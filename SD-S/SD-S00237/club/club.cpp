#include<iostream>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a1[100100],a2[100100],a3[100100];
long long ans[3];
long long mx1[100100],mx2[100100],mx3[100100];
long long mi[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%lld",&t);
	while(t--){
		memset(mx1,0,sizeof(mx1));
		memset(mx2,0,sizeof(mx2));
		memset(mx3,0,sizeof(mx3));		
		scanf("%lld",&n);
		long long ant=0;
		long long m=n/2;
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
			long long b=max(a1[i],a2[i]);
			long long c=max(b,a3[i]);							
			}
		for(int i=1;i<=n;i++){					
			if(a1[i]>=a2[i]){
				if(a1[i]>=a3[i]){
					mx1[i]=a1[i];
					ans[1]++;
					mi[i]=max(a2[i],a3[i]);
					ant+=mx1[i];
				}
				if(a1[i]<a3[i]){
					mx3[i]=a3[i];
					ans[3]++;
					mi[i]=a1[i];
					ant+=mx3[i];
				}
			}
			if(a1[i]<a2[i]){				
				if(a2[i]>=a3[i]){
					mx2[i]=a2[i];
					mi[i]=max(a3[i],a1[i]);
					ans[2]++;
					ant+=mx2[i];
				}
				if(a2[i]<a3[i]){
					mx3[i]=a3[i];
					mi[i]=a2[i];
					ans[3]++;
					ant+=mx3[i];
				}
			}						
			while(ans[1]>m){				
				long long k=0;
				long long j=0;
				long long mn=2*1e4+1;
				for(int i=1;i<=n;i++){					
					if(mx1[i]>0){
						if(mx1[i]-mi[i]<mn){
							k=i;
							mn=mx1[i]-mi[i];
						}	
					}
				}
				ant-=mn;
				mx1[k]=0;	
				ans[1]--;
			}
		    while(ans[2]>m){
				long long k=0;
				long long j=0;
				long long mn=2*1e4+1;
				for(int i=1;i<=n;i++){
					if(mx2[i]>0){	
						if(mx2[i]-mi[i]<mn){
							k=i;
							mn=mx2[i]-mi[i];	
						}	
					}
				}
				ant-=mn;
				mx2[k]=0;
				ans[2]--;
			}
		    while(ans[3]>m){
				long long k=0;
				long long j=0;
				long long mn=2*1e4+1;
				for(int i=1;i<=n;i++){
					if(mx3[i]>0){
						if(mx3[i]-mi[i]<mn){
							k=i;
							mn=mx3[i]-mi[i];
						}
					}
				}
				ant-=mn;
				mx3[k]=0;
				ans[3]--;	
			}
	    }
		printf("%lld\n",ant);
	}
	return 0;
} 
