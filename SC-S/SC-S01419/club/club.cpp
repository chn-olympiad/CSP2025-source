#include<bits/stdc++.h>
using namespace std;
int t;
int b[10005],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[10005][5];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=3;j++){
				if(a[i][j]==0)b[++cnt]=a[i][j];
			}
		}
		sort(b+1,b+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
}