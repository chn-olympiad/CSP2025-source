#include<bits/stdc++.h>
using namespace std;
int a[100005][5],d[100005]={0},z[5],c1,c2,c3;
int main(){
	freopen('club.in','r',stdin);
	freopen('club.out','w',stdout);
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		z[0]=n/2,z[1]=n/2,z[2]=n/2;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=0;l<3;l++){
					if(z[l]>0 and d[j]<d[j-1]+a[j][l]){
						d[j]=d[j-1]+a[j][l];
						z[l]--;
					}
					
				}
			}
		}
		cout<<d[n];
	}
	return 0;
} 
