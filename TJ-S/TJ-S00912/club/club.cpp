#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,j,a[i],aa[i],aaa[i],n,a1=0,a2=0,a3=0,m=99999,mi=99999,min=99999;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		for(j=0;j<n;j++){
			for(i=0;i<3;i++){
				cin>>a[i]>>aa[i]>>aaa[i];
				
			}
		}
		if(a[i]<m){
			m=a[i];
		}
		if(aa[i]<m){
			mi=aa[i];
		}
		if(a[i]<min){
			min=aaa[i];
		}
		cout<<m+mi+min;
	}
	return 0;
}
