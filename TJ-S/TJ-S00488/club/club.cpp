#include<bits/stdc++.h>
using namespace std;
int t;
int a[100010][5],sum[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag2=true,flag3=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			sum[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][2]!=0){
				flag2=false;
			}
			if(a[i][3]!=0){
				flag3=false;
			}
		}
		if(flag2&&flag3){
			int q=0;
			for(int i=1;i<=n;i++){
				q+=a[i][1];
			}
			cout<<q<<endl;
			return 0;
		}
		int q=0;
		for(int i=1;i<=n;i++){
			q+=sum[i];
		}
		cout<<q<<endl;
	}
	return 0;
}


