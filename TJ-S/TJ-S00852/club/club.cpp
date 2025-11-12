#include<bits/stdc++.h>
using namespace std;
int arr[100005][5];
int a1[100005],b1[100005],c1[100005];
bool cmp(int px1,int px2){
	return px1>px2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		bool f=1,f1=1;
		int su1=0,su2=0,su3=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			a1[i]=arr[i][1];
			b1[i]=arr[i][2];
			c1[i]=arr[i][3];
			if(arr[i][2]!=0) f=0;
			if(arr[i][3]!=0) f1=0;
		}
		if(f&&f1){
			sort(a1+1,a1+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a1[i];
			}
			cout<<sum<<endl;
			
		}else if(n==2){
			
			int maxx=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxx=max(maxx,arr[1][i]+arr[2][j]);
					}
				}
			}
			cout<<maxx<<endl;
		}else if(n==4){
			
			int maxx=0;
			for(int i=1;i<=3;i++){
				for(int i1=1;i1<=3;i1++){
					for(int i2=1;i2<=3;i2++){
						for(int i3=1;i3<=3;i3++){
							if((i==i1&&i!=i2&&i!=i3&&i2!=i3)||(i==i2&&i!=i1&&i!=i3&&i1!=i3)||(i==i3&&i!=i2&&i!=i1&&i2!=i1)||(i1==i2&&i!=i2&&i2!=i3&&i!=i3)||(i1==i3&&i!=i2&&i1!=i2&&i1!=i3)||(i2==i3&&i!=i2&&i2!=i1&&i1!=i)){
									maxx=max(maxx,arr[1][i]+arr[2][i1]+arr[3][i2]+arr[4][i3]);
								
							}
						}
					}
				}
			}
			cout<<maxx<<endl;
		}
		
	}
	
	return 0;
}


