#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][4],cnt[4],sum,mf[N][2],ms[N][2],k,c[N],l;
struct mem{
	int id;
	int vel;
}b[4];
bool cmp(mem x,mem y){return x.vel>y.vel;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		sum=l=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j],b[j].vel=a[i][j],b[j].id=j;
			sort(b+1,b+4,cmp);
			mf[i][0]=b[1].vel;
			mf[i][1]=b[1].id;
			ms[i][0]=b[2].vel;
			ms[i][1]=b[2].id;
			cnt[b[1].id]++;
			sum+=b[1].vel;
		}
		bool flag=true;
		for(int i=1;i<=3;i++)if(cnt[i]>n/2)flag=false,k=i;
		if(flag)cout<<sum<<"\n";
		else{
			for(int i=1;i<=n;i++)if(mf[i][1]==k)c[++l]=mf[i][0]-ms[i][0];
			sort(c+1,c+l+1);
			for(int i=1;i<=cnt[k]-n/2;i++)sum-=c[i];
			cout<<sum<<"\n";
		}
	}
	return 0;
} //ÆÚÍû100 
