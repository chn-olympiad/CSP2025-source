#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[3][N];
int b[3][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int mna=0x3f3f3f3f,mnb=0x3f3f3f3f,mnc=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			b[1][i]=a[1][i];
			b[2][i]=a[2][i];
			b[3][i]=a[3][i];
		}
		
		for(int i=1;i<=n;i++){
			int asd=min(min(a[1][i],a[2][i]),a[3][i]);
			a[1][i]-=asd;a[2][i]-=asd;a[3][i]-=asd;
		}
//		for(int j=1;j<=n;j++){
//			for(int i=1;i<=3;i++){
//				cout<<a[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<endl<<"9999999999999999999999999999999999999999999999999"<<'\n';
		for(int i=1;i<=n;i++){
			mna=min(a[1][i],mna);
			mnb=min(a[2][i],mnb);
			mnc=min(a[3][i],mnc);
		}
		for(int i=1;i<=n;i++){
			a[1][i]-=mna;
			a[2][i]-=mnb;
			a[3][i]-=mnc;
		}
//		for(int j=1;j<=n;j++){
//			for(int i=1;i<=3;i++){
//				cout<<a[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<endl<<"9999999999999999999999999999999999999999999999999"<<'\n';
		for(int j=1;j<=n;j++){
			int maax=0,k=0;
			for(int i=1;i<=3;i++){
				if(a[i][j]>maax){
					maax=a[i][j];k=i;
				}
			}
			for(int i=1;i<=3;i++){
				if(i!=k){
					a[i][j]=0;
				}
			}
		}
//		for(int j=1;j<=n;j++){
//			for(int i=1;i<=3;i++){
//				cout<<a[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<endl<<"9999999999999999999999999999999999999999999999999"<<'\n';
		long long sum=0;
		int aaa[N];
		for(int i=1;i<=3;i++)
			for(int j=1;j<=n;j++){
				if(a[i][j]){
					sum+=b[i][j];
					aaa[i]++;
				}
			}
		cout<<sum<<endl;
	}
	
	return 0;
}

