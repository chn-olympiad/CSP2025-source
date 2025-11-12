#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,a[maxn][5],t,f1,f2,f3,b[maxn],d,in;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;f1=1;f2=2;f3=3;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) f1=0;
			if(a[i][1]!=0||a[i][3]!=0) f2=0;
			if(a[i][1]!=0||a[i][2]!=0) f3=0;
		}
		if(f1||f2||f3){
			f1=f1+f2+f3;
			for(int i=1;i<=n;i++){
				b[i]=a[i][f1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>(n/2);i--){
				ans+=b[i];
			}
			cout<<ans<<'\n';
		}
		if(n<=2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans<<'\n';
		}
		
		
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
