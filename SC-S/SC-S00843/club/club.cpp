#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct person{
	int n,d;
};
bool cmp(person a,person b){
	return a.d<b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int n;
	int ans[T];
	for(int t=0;t<T;t++){
		ans[t]=0;
		cin>>n;
		int a[n][3];
		int c[n];
		int num[3];
		for(int i=0;i<3;i++){
			num[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				a[i][3]=0;
				if(a[i][1]>a[i][2]){
					a[i][4]=1;
					a[i][5]=2;
				}
				else{
					a[i][4]=2;
					a[i][5]=1;
				}
			}
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
				a[i][3]=1;
				if(a[i][0]>a[i][2]){
					a[i][4]=0;
					a[i][5]=2;
				}
				else{
					a[i][4]=2;
					a[i][5]=0;
				}
			}
			else{
				a[i][3]=2;
				if(a[i][0]>a[i][2]){
					a[i][4]=0;
					a[i][5]=1;
				}
				else{
					a[i][4]=1;
					a[i][5]=0;
				}
			}
			c[i]=a[i][3];
			num[a[i][3]]++;		
			ans[t]+=a[i][a[i][3]];			
		}
		int k;
		for(int i=0;i<3;i++){
			if(num[i]>n/2){
				k=i;
			}
		}
		person b[n];
		int l=0;
		for(int i=0;i<n;i++){
			if(c[i]==k){
				b[l].n=i;
				b[l].d=a[i][k];
				l++;
			}
		}
		sort(b,b+l,cmp);
		for(int i=0;i<num[k]-n/2;i++){
			ans[t]-=b[i].d; 
			
		}
	} 
	for(int i=0;i<T;i++){
		cout<<ans[i]<<endl;
	}
}
