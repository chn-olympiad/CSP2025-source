#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int sum[N];
	for(int o=1;o<=t;o++){
	int x,y,z,b1=0,b2=0,b3=0;
	int n,s=0,num=0;
	int a[N][3],b[N];
	cin >> n;
	int max1=-0x3f3f3f3f,max2=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=3;j++){
			cin >> a[i][j];
		}
		s+=a[i][2];
		s+=a[i][3];
		b[i]=a[i][1];
	}
	if(n==2){
		for(int j=1;j<=3;j++){
			if(a[1][j]>max1){
				max1=a[1][j];
					x=j;
			}
		}
		for(int j=1;j<=3;j++){
			if(a[2][j]>max2){
				max2=a[2][j];
					y=j;
			}
		}
		if(x==y){
			int min1=0x3f3f3f3f,min2=0x3f3f3f3f,q,e,mid1,mid2;
			for(int j=1;j<=3;j++){
			if(a[1][j]<min1){
				min1=a[1][j];
					q=j;
			}
		}
		for(int j=1;j<=3;j++){
			if(a[2][j]>min2){
				min2=a[2][j];
					e=j;
			}
		}
		for(int k=1;k<=3;k++){
			if(k!=x&&k!=q){
				mid1=a[1][k];
			}
		}for(int k=1;k<=3;k++){
			if(k!=y&&k!=e){
				mid2=a[2][k];
			}
		}
		sum[o]=max(mid1+max2,mid2+max1);
		break;
		}else{
			sum[o]=max1+max2;
			break;
		}
	}
	if(s==0){
		sort(b+1,b+n+1);
	    for(int z=n;z>n/2;z--){
	    	sum[o]+=b[z];
		}
	}
	
}
    for(int o=1;o<=t;o++)
        cout << sum[o] << endl;
	return 0;
}
