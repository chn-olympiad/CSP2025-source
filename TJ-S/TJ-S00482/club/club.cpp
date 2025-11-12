#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1,a2,a3,bm1=0,bm2=0,bm3=0,my=0;
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		my=0;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3&&bm1<=n/2){
				bm1++;
				my+=a1;
			}else if(a2>a1&&a2>a3&&bm2<=n/2){
				bm2++;
				my+=a2;
			}else{
				bm3++;
				my+=a3;
				
			}
		}
		cout<<my<<"\n";
	}
	return 0£»
}



