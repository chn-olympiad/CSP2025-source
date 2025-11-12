#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T;
struct node{
	int x,y,z,ma,id;
}a[N];
bool cmp(node dbp,node dvc){
	return dbp.ma>dvc.ma;
}
bool cmpa(node nn,node nnn){
	return nn.x>nnn.x;
}
int dp[300][200][11];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int flaga=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)flaga=0;
			a[i].ma=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].ma==a[i].x){
				a[i].id=1;
			}else if(a[i].ma==a[i].y){
				a[i].id=2;
			}else if(a[i].ma==a[i].z){
				a[i].id=3;
			}
		}
		if(n==2){
			int ma=-1;
//			ma=max(ma,a[1].x+a[2].x);
			ma=max(ma,a[1].x+a[2].y);
			ma=max(ma,a[1].x+a[2].z);
			ma=max(ma,a[1].y+a[2].x);
//			ma=max(ma,a[1].y+a[2].y);
			ma=max(ma,a[1].y+a[2].z);
			ma=max(ma,a[1].z+a[2].x);
			ma=max(ma,a[1].z+a[2].y);
//			ma=max(ma,a[1].z+a[2].z);
			cout<<ma<<"\n";
			continue;
		}
		if(flaga==1){
			sort(a+1,a+n+1,cmpa);
			int lim=n/2;
			long long ans=0;
			for(int i=1;i<=lim;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		int cnt[11]={0};
//		int cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<a[i].ma<<" "<<a[i].id<<"\n";
//		}
		int lim=n/2;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int td=a[i].id;
			int tx=a[i].x;
			int ty=a[i].y;
			int tz=a[i].z;
			int tma=a[i].ma;
			if(cnt[td]<lim){
//				cout<<"<lim\n"<<td<<" "<<tma<<"\n";
				cnt[td]++;
				ans+=tma;
			}else{
//				cout<<">lim\n";
				int tid,tmx=-1;
				if(cnt[1]<lim){
					if(tmx<tx){
						tid=1;
						tmx=tx;
					}
				}else if(cnt[2]<lim){
					if(tmx<ty||(tmx==ty&&cnt[2]<cnt[1])){
						tid=2;
						tmx=ty;
					}
				}else if(cnt[3]<lim){
					if(tmx<tz||(tmx==tz&&cnt[3]<cnt[2])){
						tid=3;
						tmx=tz;	
					}
				}
				cnt[tid]++;
//				cout<<tid<<" "<<tmx<<"\n";
				ans+=tmx;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
