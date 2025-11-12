#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int t,n,k[N],k1;
long long ans;
int cnt[4],maxx[N];
int a[N][4];
void s(int x1,int x2,int x3,int id)
{
	if(x1>=x2){
		if(x2>=x3) cnt[1]++,maxx[id]=1;
		else{
			if(x1>=x3) cnt[1]++,maxx[id]=1;
			else cnt[3]++,maxx[id]=3;
		}
	}
	else{
		if(x1>=x3) cnt[2]++,maxx[id]=2;
		else{
			if(x2>=x3) cnt[2]++,maxx[id]=2;
			else cnt[3]++,maxx[id]=3;
		}
	}
	return;
}
void ch(int x,int y,int z){
	k1=0;
	for(int i=1;i<=n;i++){
		if(maxx[i]!=x) continue;
		k1++;
		k[k1]=min(a[i][x]-a[i][y],a[i][x]-a[i][z]);
	}
	sort(k+1,k+k1+1);
	for(int i=1;i<=k1-(n/2);i++){
		ans-=k[i];
	}
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			s(a[i][1],a[i][2],a[i][3],i);
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][maxx[i]];
		}
		if(cnt[1]<=(n/2) && cnt[2]<=(n/2) && cnt[3]<=(n/2)){
			cout << ans;
			puts("");
			continue;
		}
		if(cnt[1]>(n/2)) ch(1,2,3);
		else if(cnt[2]>(n/2)) ch(2,1,3);
		else ch(3,2,1);
		cout << ans;
		puts("");
	}
	return 0;
} 
