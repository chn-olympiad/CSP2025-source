#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ndy=0;
	int a[400][400]={};
	int b[10000]={};
	int b1=0,b2=0,b3=0;
	int bb3=0;
	int bb1=0,bb2=0;
	cin>>t;

	for (int i=1;i<=t;i++){
		
		cin>>n;
		for (int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				cin>>a[j][z];
			}
			
		}
		
		for (int j=0;j<n;j++){
				if (a[j][1]>a[j][2]&&a[j][3]){
					b1+=a[j][1];
					bb1++;
				}
				else if (a[j][2]>a[j][1]&&a[j][3]){
					b2+=a[j][2];
					bb2++;
				}
				else if (a[j][3]>a[j][1]&&a[j][3]){
					b3+=a[j][3];
					bb3++;
				}
		}
		if(ndy>bb1 && ndy>bb2 && ndy>bb3){
			cout<<b1+b2+b3<<endl;
		} 

		bb1==0;
		bb2==0;
		bb3==0;
		b2==0;
		b1==0;
		b3==0;
		
		
		
		return 0;
	}
}
