#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<cstring>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int T,n,a[5][200000],j[5],l,k,tot=0;
long long ans=0;
struct node{
	int id,x;
}b[100000];
bool cmp(node x,node y){
	if(a[1][y.id]-a[2][y.id]>=a[1][x.id]-a[2][x.id])return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		j[1]=j[2]=j[3]=j[0]=tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])j[1]++,a[0][i]=1;
			else if(a[3][i]>=a[2][i]&&a[1][i]<=a[3][i])j[3]++,a[0][i]=3;
			else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i])j[2]++,a[0][i]=2;
			int tx=max(a[1][i],max(a[2][i],a[3][i]));
			int tn=min(a[1][i],min(a[2][i],a[3][i]));
			a[2][i]=(a[1][i]+a[2][i]+a[3][i])-tx-tn;
			a[1][i]=tx;
			a[3][i]=tn;
		//	cout<<a[0][i]<<"  ";
		}
		l=ans=0;
		if(j[1]>(n/2))l=1;
		if(j[2]>(n/2))l=2;
		if(j[3]>(n/2))l=3;
		if(l!=0){
			k=j[l]-(n/2);
		//	cout<<k<<" "<<l<<"\n";
			for(int i=1;i<=n;i++)if(a[0][i]==l)b[++tot].id=i;
			sort(b+1,b+1+tot,cmp);
			for(int i=1;i<=k;i++){
				a[1][b[i].id]=a[2][b[i].id];
			}
		}
	//	cout<<"__________";
		for(int i=1;i<=n;i++){
			ans+=a[1][i];
		//	cout<<a[1][i]<<"  ";
		}
		printf("%lld\n",ans);
	}
	return 0;
}
