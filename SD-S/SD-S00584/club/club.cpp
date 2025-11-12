#include<bits/stdc++.h>
#define int long long
 
using namespace std;

const int N=1e5+5;
const int M=3e2+5;

int T;
int n;
int a[N],b[N],c[N];
//int f[N][5];
int f[M][M][M];

int max(int x,int y){
	return x>y?x:y; 
}
void solve(){
	
	cin>>n;
	for(int j=n/2;j>=0;j--){
		for(int k=n/2;k>=0;k--){
			for(int l=n/2;l>=0;l--){
				f[j][k][l]=0;
			}
		}
	}
	int flg=1,flg2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0||c[i]!=0)flg=0;
		if(c[i]!=0)flg2=0;
	}
	if(flg){
		sort(a+1,a+1+n,greater<int>());
		int sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum<<'\n';
		return;
	}else if(flg2){
		int macs=0;
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					if(j>0)
					f[j][k][0]=max(f[j-1][k][0]+a[i],f[j][k][0]);
					if(k>0)
					f[j][k][0]=max(f[j][k-1][0]+b[i],f[j][k][0]);
//					if(l>0)
//					f[j][k][0]=max(f[j][k][l-1]+c[i],f[j][k][l]);
					if(j+k==n){
						macs=max(macs,f[j][k][0]);
					}
				}
			}
		}
		cout<<macs<<"\n";
		return;
	}
	int macs=0;
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				for(int l=n/2;l>=0;l--){
					if(j>0)
					f[j][k][l]=max(f[j-1][k][l]+a[i],f[j][k][l]);
					if(k>0)
					f[j][k][l]=max(f[j][k-1][l]+b[i],f[j][k][l]);
					if(l>0)
					f[j][k][l]=max(f[j][k][l-1]+c[i],f[j][k][l]);
					if(j+k+l==n){
						macs=max(macs,f[j][k][l]);
					}
				}
			}
		}
	}
	cout<<macs<<"\n";
}
int sa[100005],sb[100005],sc[100005];
int ta[100005],tb[100005],tc[100005];
void solve2();
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>T;
	while(T--)solve();
	return 0;
}

void solve2(){
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		ta[i]=a[i];tb[i]=b[i];tc[i]=c[i];
		sum+=a[i]+b[i]+c[i];
	}
}

