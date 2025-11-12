#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int t,n;
int a[maxn],b[maxn],c[maxn],ans[maxn],cnt[3],yb[maxn],ls[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ANS=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans[i]=1,cnt[1]++;
				yb[i]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans[i]=2,cnt[2]++;
				yb[i]=b[i]-max(a[i],c[i]);
			}
			else{
				ans[i]=3,cnt[3]++;
				yb[i]=c[i]-max(a[i],b[i]);
			} 
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==1)ANS+=a[i];
			else if(ans[i]==2)ANS+=b[i];
			else ANS+=c[i];
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2);
		else if(cnt[1]>n/2){
			
			int z=cnt[1]-n/2,cc=0;
			for(int i=1;i<=n;i++){
				if(ans[i]==1)ls[++cc]=yb[i];
			}
			sort(ls+1,ls+cc+1);
			for(int i=1;i<=z;i++){
				ANS-=ls[i];
			}
		}
		else if(cnt[2]>n/2){
			int z=cnt[2]-n/2,cc=0;
			for(int i=1;i<=n;i++){
				if(ans[i]==2)ls[++cc]=yb[i];
			}
			sort(ls+1,ls+cc+1);
			for(int i=1;i<=z;i++){
				ANS-=ls[i];
			}
		}
		else if(cnt[3]>n/2){
			int z=cnt[3]-n/2,cc=0;
			for(int i=1;i<=n;i++){
				if(ans[i]==3)ls[++cc]=yb[i];
			}
			sort(ls+1,ls+cc+1);
			for(int i=1;i<=z;i++){
				ANS-=ls[i];
			}
		}
		cout<<ANS<<endl;
	}
	return 0;
}

