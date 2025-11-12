#include<bits/stdc++.h>
using namespace std;
int sj[2005][2005];
struct qj{
	int ks,js;
};
qj q[100000000];
bool cmp(qj a,qj b){
	if(a.ks<b.ks){
		return 1;
	}else if(a.ks==b.ks){
		return a.js<b.js;
	}else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,yh=0,sum=1,t=0,visit;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&sj[i][i]);
	}
	for(int i=1;i<=n;i++){
		yh=sj[i][i];
		if(yh==k){
			q[t].js=i;
			q[t].ks=i;
			t++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			yh=(sj[i][j-1]^sj[j][j]);
			sj[i][j]=yh;
			if(yh==k){
				q[t].js=j;
				q[t].ks=i;
				t++;
				continue;
			}
		}
	}
	sort(q,q+t-1,cmp);
	visit=q[0].js;
	for(int i=1;i<t;i++){
		if(q[i].ks>visit){
			sum++;
			visit=q[i].js;
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
