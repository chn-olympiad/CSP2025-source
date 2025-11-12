#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
int nt[100005],cnt[3],ch[100005];
long long ans;
int soter[100005],stid;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			signed a[3]={0,0,0};
			cin>>a[0]>>a[1]>>a[2];
			if(a[0]>=a[1]&&a[0]>=a[2]){
				cnt[0]++;
				ch[i]=0;
				nt[i]=a[0]-max(a[1],a[2]);
				ans+=a[0];
			}
			else if(a[1]>=a[0]&&a[1]>=a[2]){
				cnt[1]++;
				ch[i]=1;
				nt[i]=a[1]-max(a[0],a[2]);
				ans+=a[1];
			}
			else if(a[2]>=a[0]&&a[2]>=a[1]){
				cnt[2]++;
				ch[i]=2;
				nt[i]=a[2]-max(a[0],a[1]);
				ans+=a[2];
			}
		}
		int mb=max({cnt[0],cnt[1],cnt[2]})-n/2;
		if(mb<=0){
			cout<<ans<<"\n";
			continue;
		}
		int id=0;
		if(cnt[0]==max({cnt[0],cnt[1],cnt[2]})){
			id=0;
		}
		else if(cnt[1]==max({cnt[0],cnt[1],cnt[2]})){
			id=1;
		}
		else if(cnt[2]==max({cnt[0],cnt[1],cnt[2]})){
			id=2;
		}
		stid=0;
		for(int i=1;i<=n;i++){
			if(ch[i]!=id)continue;
			soter[++stid]=nt[i];
		}
		sort(soter+1,soter+stid+1);
		for(int i=1;i<=mb;i++){
			ans-=soter[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

