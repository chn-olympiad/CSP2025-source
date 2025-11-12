#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n,j,t,a[100010][3],b[3]={0},ans=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
			a[n][1]+=max(a[1][2],a[1][3]);
			a[n][2]+=max(a[1][1],a[1][3]);
			a[n][3]+=max(a[1][1],a[1][2]);
			ans=max(a[n][1],max(a[n][2],a[n][3]));
		cout<<ans<<endl;
		b[3]={0},ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}