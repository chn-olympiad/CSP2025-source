#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,m,x;
int a[1110];
signed main(){
	//×¢ÒâÌæ»»ºÍ×¢ÊÍ
	FI("seat");
	FO("seat");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		a[i]=x*-1;
	//	cout<<a[i]<<" ";
	}
	//cout<<endl;
	int xmcj=a[1];
	sort(a+1,a+n*m+1);
	int i,j;
//	for(int i=1;i<=n*m;i++){
//		cout<<i<<a[i]<<" ";
//	}
	//cout<<endl;
	int hao=0;
	for(i=1;i<=m;++i){
		//cout<<i;
		if(i%2==1){
			for(j=1;j<=n;++j){
			//	cout<<j;
				hao++;
				//cout<<a[hao];
				if(a[hao]==xmcj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(j=n;j>=1;--j){
			//	cout<<j;
				hao++;
				//cout<<a[hao];
				if(a[hao]==xmcj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	//	cout<<endl;
	}
	return 0;
}

