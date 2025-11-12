//王岚清 SN-S00487 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct node{
	int w,num;
};
vector<node> a[100005];
bool cmp(node xx,node yy){
	return xx.w>yy.w;
}
int cnt[5];
long long ans;
bool cmp2(vector<node> xx,vector<node> yy){
	if(xx[0].w-xx[1].w==yy[0].w-yy[1].w){
		return xx[0].w-yy[2].w>yy[0].w-yy[2].w;
	}else{
		return xx[0].w-xx[1].w>yy[0].w-yy[1].w;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			node wlqk1,wlqk2,wlqk3;
			cin>>wlqk1.w>>wlqk2.w>>wlqk3.w;
			wlqk1.num=0,wlqk2.num=1,wlqk3.num=2;
//			if(k1.w>k2.w and k1.w>k3.w){
//				if(k2.w<k3.w)swap(k2,k3);
//			}else if(k2.w>k1.w and k2.w>k3.w){
//				swap(k2,k1);
//				if(k2.w<k3.w)swap(k2,k3);
//			}else if(k3.w>k1.w and k3.w>k2.w){
//				swap(k3,k1);
//				if(k2.w<k3.w)swap(k2,k3);
//			}
			a[i].push_back(wlqk1),a[i].push_back(wlqk2),a[i].push_back(wlqk3);
			sort(a[i].begin(),a[i].end(),cmp);
		}
//		printf("@");
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				if(cnt[a[i][j].num]<n/2){
					ans+=a[i][j].w;
					cnt[a[i][j].num]++;
					break;
				}
			}
		}
//		printf("#");
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		ans=0;
		memset(cnt,0,sizeof cnt);
	}

	
	return 0;
}
