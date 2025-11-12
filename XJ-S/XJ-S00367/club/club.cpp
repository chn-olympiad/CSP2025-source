#include<bits/stdc++.h>
using namespace std;
int a[100010][10],b[100010],c[100010],d[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,x=1;
	int f[10];
	cin>>t;
	while(t--){
		int n,y=0,z=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
	    }
	    int j1[100010],j2[100010],j3[100010];
	    for(int i=1;i<=n;i++){
	    	int max1=0,max2=0,min=0;
	    	for(int j=1;j<=3;j++){
	    		if(a[i][j]>=max1){
	    			max1=a[i][j];
	    			j1[i]=j;
				}else if(a[i][j]<max1 && a[i][j]>min){
					max2=a[i][j];
					j2[i]=j;
				}else if(a[i][j]<max1 && a[i][j]>max2){
					min=max2;
					j3[i]=j2[i];
					max2=a[i][j];
					j2[i]=j;
				}else if(a[i][j]<max2){
					min=a[i][j];
					j3[i]=j;
				}
			}
			b[i]=max1;
			c[i]=max2;
			d[i]=min;
		}
		int e=n/2;
		int g1=0,g2=0,g3=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[i]==b[j]){
					if(j1[i]==j1[j]==1){
						g1++;
					}else if(j1[i]==j1[j]==2){
						g2++;
					}else if(j1[i]==j1[j]==3){
						g3++;
					}
				}
			}
		}
		if(g1==0 && g1<=e-1){
			for(int i=1;i<=n;i++){
				if(j1[i]==1){
					f[x]+=b[i];
				}
			}
		}else if(g1>e-1){
			sort(b,b+1);
			for(int i=2;i<=e-1;i++){
				f[x]+=b[i];
			}
		}
		if(g2==0 && g2<=e-1){
			for(int i=1;i<=n;i++){
				if(j1[i]==2){
					f[x]+=b[i];
				}
			}
		}
		else if(g2>e-1){
			sort(b,b+1);
			for(int i=2;i<=e-1;i++){
				f[x]+=b[i];
			}
		}
		if(g3==0 && g3<=e-1){
			for(int i=1;i<=n;i++){
				if(j1[i]==3){
					f[x]+=b[i];
				}
			}
		}else if(g3>e-1){
			sort(b,b+1);
			for(int i=2;i<=e-1;i++){
				f[x]+=b[i];
			}
		}
		x++; 
	}
	for(int i=1;i<x;i++){
		cout<<f[i]<<endl;
	}
	return 0;
} 
