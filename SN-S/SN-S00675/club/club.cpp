#include<bits/stdc++.h>
using namespace std;
struct student{
	int good1;
	int good2;
	int good3;
}a[1000010];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,m;
	cin>>n;
	long long sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a[i].good1>>a[i].good2>>a[i].good3;
			if(a[i].good1>a[i].good2 && a[i].good1>a[i].good3){
				if(sum1<=m/2){
					sum1++;
					sum4+=a[i].good1;
				}else{
					if(a[i].good2>=a[i].good3){
						sum1+=sum1-m;
						sum2+=m;
						sum5+=a[i].good2;
					}
					if(a[i].good2<=a[i].good3){
						sum1+=sum1-m;
						sum3+=m;
						sum6+=a[i].good3;
					}
				}
			}
			if(a[i].good2>a[i].good1 && a[i].good2>a[i].good3){
				if(sum2<=m/2){
					sum2++;
					sum5+=a[i].good2;
				}else{
					if(a[i].good1>=a[i].good3){
						sum2+=sum2-m;
						sum1+=m;
						sum4+=a[i].good1;
					}
					if(a[i].good1<=a[i].good3){
						sum2+=sum2-m;
						sum3+=m;
						sum6+=a[i].good3;
					}
				}
			}
			if(a[i].good3>a[i].good1 && a[i].good3>a[i].good2){
				if(sum3<=m/2){
					sum3++;
					sum6+=a[i].good3;
				}else{
					if(a[i].good1>=a[i].good2){
						sum3+=sum3-m;
						sum1+=m;
						sum4+=a[i].good1;
					}
					if(a[i].good2>=a[i].good1){
						sum3+=sum3-m;
						sum2+=m;
						sum5+=a[i].good2;
					}
				}
			}
		}
		cout<<sum4+sum5+sum6;
	}
	
	return 0;
}
