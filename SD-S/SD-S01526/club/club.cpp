#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100011],sa[100011],x,ob;
long long ans=0;
int check(){
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		cnt[sa[i]]++;
	}
	int n1=n/2;
	x=0;
	ob=cnt[1]-n1;
	if(ob>0){
		x=1;
		return 1;
	}
	ob=cnt[2]-n1;
	if(ob>0){
		x=2;
		return 2;
	}
	ob=cnt[3]-n1;
	if(ob>0){
		x=3;
		return 3;
	}
	return 0;
}
void mysum(){
	for(int i=1;i<=n;i++){
		ans+=a[sa[i]][i];
	}
}
void solve(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
		if(a[1][i]>=a[2][i]){
			if(a[1][i]>a[3][i])sa[i]=1;
			else sa[i]=3;
		}else{
			if(a[2][i]>a[3][i])sa[i]=2;
			else sa[i]=3;
		}
	}
	
	if(check()){
		for(int a1=1;a1<=ob;a1++){
			int mini=1;
			for(int i=1;i<=n;i++){
				if(sa[i]!=x)continue;
				if(a[x][i]<a[x][mini])mini=i;
			}
			int bu=0;
    		for(int i=1;i<=3;i++){
				if(i!=x){
					if(!bu)bu=i;
					else if(a[i][mini]>a[bu][mini])bu=i;
				}
			}
			sa[mini]=bu;
		}
	}
	ans=0;
	mysum();
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int a1=1;a1<=t;a1++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
