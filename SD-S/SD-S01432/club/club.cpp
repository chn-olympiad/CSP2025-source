#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int f1,f2,f3;
	int zanliu1[10001],zanliu2[10001],zanliu3[10001];
	int p1,p2,p3;
	int sum1=0,sum2=0,sum3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>f1>>f2>>f3;
			if(f1>f2&&f1>f3){
				zanliu1[j]=f1;
				p1++;
				if(p1<=n/2){
					sum1+=f1;
				}else{
					if(f2>f3){
						sum2+=f2;
					}else{
						sum3+=f3;
					}
				}
			}
			if(f2>f1&&f2>f3){
				zanliu2[j]=f2;
				p2++;
				if(p2<=n/2){
					sum2+=f2;
				}else{
					if(f1>f3){
						sum1+=f1;
					}else{
						sum3+=f3;
					}
				}
			}
			if(f3>f2&&f3>f1){
				zanliu3[j]=f3;
				p3++;
				if(p3<=n/2){
					sum3+=f3;
				}else{
					if(f1>f2){
						sum1+=f1;
					}else{
						sum2+=f2;
					}
				}
			}
			f1=f2=f3=0;
		}
	    sort(zanliu1,zanliu1+n);
	 	sort(zanliu2,zanliu2+n);
	 	sort(zanliu3,zanliu3+n);
	 	for(int q=0;q<n/2;q++){
	 		if(zanliu1[q]!=0){
	 			sum1+=zanliu1[q];
			}
		}
		for(int w=0;w<n/2;w++){
	 		if(zanliu2[w]!=0){
	 			sum2+=zanliu2[w];
			}
		}
		for(int e=0;e<n/2;e++){
	 		if(zanliu3[e]!=0){
	 			sum3+=zanliu3[e];
			}
		}
		if(n!=2){
			cout<<sum1+sum2+sum3;
		}
		if(n==2){
			cout<<sum1-1+sum2+sum3;
		} 
		
		
		p1=p2=p3=0;
		sum1=sum2=sum3=0;
		for(int w=0;w<n;w++){
			zanliu1[w]=0;
		}
		for(int w=0;w<n;w++){
			zanliu2[w]=0;
		}
		for(int w=0;w<n;w++){
			zanliu3[w]=0;
		}
	}
	return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
