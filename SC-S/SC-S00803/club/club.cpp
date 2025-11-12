#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long n,a[maxn][5],cnt[5];
struct stu{
	int a1,a2,a3;
}c[maxn];
bool cmp(stu a,stu b){
	return max(a.a1,max(a.a2,a.a3))>max(b.a1,max(b.a2,b.a3));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		memset(c,0,sizeof c);
		cin>>n;
		int lim=n/2;
		long long ans=0;
		bool j12=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			c[i].a1=a[i][1];
			c[i].a2=a[i][2];
			c[i].a3=a[i][3];
			if(!j12&&(a[i][2]||a[i][3])) j12=1;
		}
		if(j12==0){
			int w[maxn];
			for(int i=1;i<=n;i++){
				w[i]=a[i][1];
			}
			sort(w+1,w+n+1);
			for(int i=n;i>lim;i--)
			ans+=w[i];
			cout<<ans<<'\n';
			break;
		}
		sort(c+1,c+n+1,cmp);
		//for(int i=1;i<=n;i++) cout<<c[i].a1<<c[i].a2<<c[i].a3<<endl;
		for(int i=1;i<=n;i++){
			bool vis=0;
			int mx=max(c[i].a1,max(c[i].a2,c[i].a3));
			//cout<<"max="<<mx<<'\n';
			if(mx==c[i].a1&&!vis){
				if(cnt[1]<lim){
					vis=1;ans+=c[i].a1;cnt[1]++;
				}else{
					int w= c[i].a2>c[i].a3? 2:3;
					int r= w==2? 3:2;
					if(cnt[w]<lim){
						vis=1;ans+=max(c[i].a2,c[i].a3);cnt[w]++;
					}else{
						vis=1;ans+=min(c[i].a2,c[i].a3);cnt[r]++;
					}
				}
			}
			if(mx==c[i].a2&&!vis){
				//cout<<cnt[2]<<" "<<lim<<'\n';
				if(cnt[2]<lim){
					vis=1;ans+=c[i].a2;cnt[2]++;
					//cout<<"enter"<<'\n';
				}else{
					int w= c[i].a1>c[i].a3? 1:3;
					int r= w==1? 3:1;
					if(cnt[w]<lim){
						vis=1;ans+=max(c[i].a1,c[i].a3);cnt[w]++;
					}else{
						vis=1;ans+=min(c[i].a1,c[i].a3);cnt[r]++;
					}
				}
			}
			if(mx==c[i].a3&&!vis){
				if(cnt[3]<lim){
					vis=1;ans+=c[i].a3;cnt[3]++;
				}else{
					int w= c[i].a2>c[i].a1? 2:1;
					int r= w==2? 1:2;
					if(cnt[w]<lim){
						vis=1;ans+=max(c[i].a2,c[i].a1);cnt[w]++;
					}else{
						vis=1;ans+=min(c[i].a2,c[i].a1);cnt[r]++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 