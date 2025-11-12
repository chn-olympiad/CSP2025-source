#include<bits/stdc++.h>
using namespace std;
int t, n;
/*short clud{
	 t,y,u;
}o[100010];*/
int e[100010],b[100010],c[100010];
//int q[50010],r[50010],w[50010];
int ans=0;
short cmp(int x,int y){
	return e[x]>e[y];
}
int main(){
freopen("clud.in","r",stdin);
freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i]>>b[i]>>c[i];
	}
		cmp(1,n+1);
		for(int i;i<=n/2;i++){
			ans+=e[i];
		}
		cout<<ans;
	}
	return 0;
}
