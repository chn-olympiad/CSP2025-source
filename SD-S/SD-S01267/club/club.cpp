#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int N=1e5+7;
int T,n,a[N][4],num[4],flag[N];
struct node{
	int x,y,w;
}c[4*N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(num,0,sizeof(num));
		memset(flag,0,sizeof(flag));
		cin>>n;
		int mid=n/2,Imax,ans=0,idx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			Imax=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=Imax;
			for(int j=1;j<=3;j++){
				int t=Imax-a[i][j];
				if(t!=0){
					c[++idx]={i,j,t};
				}
				else{
					num[j]++;
				}
			}
		}
		sort(c+1,c+idx+1,cmp);
		for(int i=1;i<=3;i++){
			if(num[i]>mid){
				int point=num[i]-mid,sum=0;
				for(int j=1;j<=idx;j++){
					if(sum==point) break;
					if(c[j].y!=i && flag[c[i].x]==0){
						ans-=c[j].w;
						sum++;
					}
				}
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
