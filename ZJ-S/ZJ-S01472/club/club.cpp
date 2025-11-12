#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100010][3],x[100010],s[100010],sm[3],ans;
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=k=sm[0]=sm[1]=sm[2]=0;
		for(int i=1;i<=n;i++){
			x[i]=0,s[i]=1e5;
			for(int j=0;j<3;j++)cin>>a[i][j];
			for(int j=1;j<3;j++)if(a[i][j]>a[i][x[i]])x[i]=j;
			for(int j=0;j<3;j++)if(j!=x[i])s[i]=min(s[i],a[i][x[i]]-a[i][j]);
			sm[x[i]]++,ans+=a[i][x[i]];
		}
		for(int i=1;i<3;i++)if(sm[i]>sm[k])k=i;
		for(int i=1;i<=n;i++)if(x[i]!=k)s[i]=1e5;
		sort(s+1,s+n+1);
		for(int i=1;i<=sm[k]-n/2;i++)ans-=s[i];
		cout<<ans<<"\n";
	}
	return 0;
}
