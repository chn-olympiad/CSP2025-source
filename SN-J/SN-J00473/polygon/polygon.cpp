//SN-J00473 曹博皓 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],cnt=0;
signed main(){
	   freopen("polygon.in","r",stdin);
	   freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int y=j+1;y<=n;y++){
				if(a[i]+a[j]>=a[y]&&a[y]+a[j]>=a[i]&&a[i]+a[y]>=a[j]){
					cnt++;
				}
			}
		}
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int y=j+1;y<=n-1;y++){
				for(int x=y+1;x<=n;x++){
					if(a[i]+a[j]+a[y]>=a[x]&&a[x]+a[j]+a[y]>=a[i]&&a[i]+a[x]+a[y]>=a[j]&&a[i]+a[j]+a[x]>=a[y]){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt-1;
    return 0;
}

