#include<bits/stdc++.h>
using namespace std;
int t,n,ai[10010][5],h,n1,r1,r2,r3,j=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		n1=n/2;
		while(j<=n){
			cin>>ai[j][1]>>ai[j][2]>>ai[j][3];
			if(ai[j][1]>ai[j][2]&&ai[j][1]>ai[j][3]){
				h+=ai[j][1];
				r1++;
			}
			else if(ai[j][2]>ai[j][1]&&ai[j][2]>ai[j][3]){
				h+=ai[j][2];
				r2++;
			}
			else{
				h+=ai[j][3];
				r3++;
			}
			j++;
		}
		if(r1>n1){
			h-=ai[j][1];
			if(ai[j][2]>ai[j][3]){
				h+=ai[j][2];
			}
			else{
				h+=ai[j][3];
			}
		}
		if(r2>n1){
			h-=ai[j][2];
			if(ai[j][1]>ai[j][3]){
				h+=ai[j][1];
			}
			else{
				h+=ai[j][3];
			}
		}
		if(r3>n1){
			h-=ai[j][3];
			if(ai[j][2]>ai[j][1]){
				h+=ai[j][2];
			}
			else{
				h+=ai[j][1];
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
