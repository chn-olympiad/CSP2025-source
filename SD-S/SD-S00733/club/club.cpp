#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int kkll,n,a[4][N],ans,cnt[N];
struct node{
	int maxn,smaxn,num;
}zzr[N];
bool cmp(node x,node y){
	return x.num>y.num; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>kkll;
	while(kkll--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=0,smx=0,mxn,smxn;
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				if(x>=mx){
					smx=mx;
					smxn=mxn;
					mx=x;
					mxn=j;
				}
				else if(x>=smx){
					smx=x;
					smxn=j;
				}
			}
			//cout<<mx<<' '<<smx<<' '<<mxn<<" "<<smxn<<endl;
			zzr[i].maxn=mxn,zzr[i].smaxn=smxn,zzr[i].num=mx-smx;
			ans+=smx;
		}
		sort(zzr+1,zzr+1+n,cmp);
		//for(int i=1;i<=n;i++) cout<<zzr[i].num<<" "<<zzr[i].maxn<<endl;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			if(cnt[zzr[i].maxn]<n/2) ans+=zzr[i].num,cnt[zzr[i].maxn]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
