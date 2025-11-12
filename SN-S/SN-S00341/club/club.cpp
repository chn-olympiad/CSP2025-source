#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100000][5],x[100000],y[100000],z[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	//cout << t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int xi=0,yi=0,zi=0;
		for(int i =1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])){
				xi++,x[xi]=a[i][1];
			}
			else if(a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])){
				yi++,y[yi]=a[i][2];
			}
			else{
				zi++,z[zi]=a[i][3];
			}
		}
		sort(x+1,x+1+xi);
		
		if(xi>n/2){
			for(int i =1;i<=xi-n/2;i++){
				for(int j =1;j<=n;j++){
					if(a[j][1]==x[i]){
						x[i]=0;
						if(a[j][2]>a[j][3]){
							yi++;
							y[yi]=a[j][2];
						}
						else{
							zi++;
							z[zi]=a[j][3];
						}
					}
				}
			}
		}
		sort(y+1,y+1+yi);
		if(yi>n/2){
			for(int i =1;i<=yi-n/2;i++){
				for(int j =1;j<=n;j++){
					if(a[j][2]==y[i]){
						y[i]=0;
						zi++;
						z[zi]=a[j][3];
					}
				}
			}
		}
		sort(z+1,z+1+zi);
		if(zi>n/2){
			for(int i =1;i<=zi-n/2;i++){
				for(int j =1;j<=n;j++){
					if(a[j][3]==z[i]){
						z[i]=0;
						yi++;
						y[yi]=a[j][2];
					}
				}
			}
		}
		long long cnt=0;
		for(int i =1;i<=xi;i++)cnt+=x[i];
		for(int i =1;i<=yi;i++)cnt+=y[i];
		for(int i =1;i<=zi;i++)cnt+=z[i];
		cout<<cnt<<"\n";
	}
	return 0;
}
