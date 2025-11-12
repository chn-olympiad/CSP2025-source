#include<bits/stdc++.h>
using namespace std;
struct Road{
	int r;
	int cl;
	int mo;
};
int main(){
	int i,j,a[10010],n,m,k,num=0,c[100010];
	long long ans=0;
	Road b[100010];
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&b[i].r,&b[i].cl,&b[i].mo);
		ans+=b[i].mo;
		c[b[i].r]++,c[b[i].cl]++;
	}
	for(i=1;i<=m-1;i++){
		for(j=1;j<=m-1;j++){
			if(b[j].mo>b[j+1].mo){
				swap(b[j],b[j+1]);
			}
		}
	}
	for(i=m;num<=n-1;i--){
		if((c[b[i].r]--)!=0&&(c[b[i].cl]--)!=0){
			ans-=b[i].mo;
			c[b[i].r]--;
			c[b[i].cl]--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}