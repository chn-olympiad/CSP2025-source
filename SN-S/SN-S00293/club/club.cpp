#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
int a[N][4],n,b[N],tot,v[N];
void work(){
	cin>>n;
	int x=0,y=0,z=0,ans=0,ret=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max(a[i][3],max(a[i][1],a[i][2]));
		if(a[i][1]==mx)++x,ans+=a[i][1],v[i]=1;
		else if(a[i][2]==mx)++y,ans+=a[i][2],v[i]=2;
		else ++z,ans+=a[i][3],v[i]=3;
	}
	if(max(max(x,y),z)>n/2){
		tot=0;
		for(int i=1;i<=n;i++){
			if(v[i]==1&&x>n/2)b[++tot]=a[i][1]-max(a[i][2],a[i][3]);
			if(v[i]==2&&y>n/2)b[++tot]=a[i][2]-max(a[i][1],a[i][3]);
			if(v[i]==3&&z>n/2)b[++tot]=a[i][3]-max(a[i][1],a[i][2]);
		}
		int cnt=max(max(x,y),z)-n/2;
		sort(b+1,b+tot+1);
		for(int i=1;i<=cnt;i++)ret+=b[i];
	}
	ans-=ret;
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--)work();
	return 0;
}

