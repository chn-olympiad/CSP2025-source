#include<bits/stdc++.h>
using namespace std;

int n, t, z;
int a[100004][3], f[100004][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}

		z = n/2;
		int ans = 0, o = 0, tw = 0, th = 0;		
		if(n == 2){
			int on = max(a[1][1]+a[2][3],a[1][1]+a[2][3]);
			int to = max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			int thr = max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			cout<<max(max(on,to),max(to,thr))<<endl;		
			continue;
		}
		
		for(int i = n;i >= 1;i--){
			for(int j = 1;j <= 3;j++){
				f[i][j] = a[i][j] + max(max(f[i+1][1],f[i+1][2]),max(f[i+1][2],f[i+1][3]));
			}
		}
		cout<<max(max(f[1][1],f[1][2]),max(f[1][2],f[1][3]))<<endl;

	}

	return 0;
}