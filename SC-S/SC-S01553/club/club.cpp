#include<iostream>
using namespace std;
const int MAXN=1e5+7;
int nn[MAXN][5],num[5];
int ans=0;
int cmpa(int a,int b,int c){
	int maxx;
	if(a>b) maxx=a;
	else maxx=b;
	if(maxx<c) maxx=c;
	return maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&nn[i][1],&nn[i][2],&nn[i][3]);
			cout<<cmpa(nn[i][1],nn[i][2],nn[i][3])<<endl;
			ans+=cmpa(nn[i][1],nn[i][2],nn[i][3]);
		}
		cout<<ans<<endl;
	}
	return 0;
}