#include<iostream>
using namespace std;
int mypi(int n1,int n2){
	for(int i =0;i<n2;i++){
	n1*=n1;
	}
	return n1;
}
void solve(){
	int n;
	scanf("%d",n);
	int lim=n/2;
	int my[n][3];
	int ans=0;
	for(int i =0;i<n;++i){
		scanf("%d%d%d",my[i][0],my[i][1],my[i][2]);
	}
	for(int i=0;i<mypi(3,n);++i){
		int bh=i;
		int section[3]={0,0,0};
		bool flag=true;
		int tmp = 0;
		for(int j=0;j<n;++j){
			section[bh%3]+=1;
			if (section[bh%3]>lim){
				flag=false;
				break;
			}
			tmp+=my[j][bh%3];
			bh/=3;
		}
		if(flag and tmp>ans){
			ans= tmp;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",t);
	for(int i=0;i<t;++t){
		solve();
	}
	return 0;
}
