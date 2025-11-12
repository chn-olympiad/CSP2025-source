#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=2e5+10;
int f[N][4];
int cnt[N][4][4];
int n;
int a[N][4];
int fl1,fl2,fl3;
void work(){
	cin>>n;
	fl1=fl2=fl3=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			
		}
		if(a[i][1]) fl1=0;
		if(a[i][2]) fl2=0;
		if(a[i][3]) fl3=0;
	}

	for(int i=1;i<=n;i++){
//		int k=max(f[i-1][1],max(f[i-1][2],f[i-1][3])),p=0;
//		if(k==f[i-1][1]) p=1;
//		if(k==f[i-1][2]) p=2;
//		if(k==f[i-1][3]) p=3;
//		//cout<<"debug:"<<k<<" "<<f[i-1][1]<<" "<<f[i-1][2]<<" "<<f[i-1][3]<<"\n";	
		for(int p=1;p<=3;p++){
			for(int j=1;j<=3;j++){
				if(cnt[i-1][p][j]+1>(n/2)){
				//	cout<<0<<" ";
					continue;
				}
				if(f[i-1][p]+a[i][j]>f[i][j]){
					f[i][j]=f[i-1][p]+a[i][j];
					cnt[i][j][1]=cnt[i-1][p][1];
					cnt[i][j][2]=cnt[i-1][p][2];
					cnt[i][j][3]=cnt[i-1][p][3];
					cnt[i][j][j]++;					
				}
			//	cout<<f[i][j]<<" ";
			}
		//	cout<<"\n";			
		}

	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			for(int k=1;k<=3;k++){
//				cout<<cnt[i][j][k]<<",";
//			}
//			cout<< "  ";
//		}
//		cout<<"\n"; 
//	}
	cout<<max({f[n][1],f[n][2],f[n][3]})<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		work();
	}
	
	return 0;
}
