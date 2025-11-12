#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,i,len[10],b[5][100010],a[100010][5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		len[1]=len[2]=len[3]=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				b[1][++len[1]]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				b[2][++len[2]]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				ans+=a[i][3];
				b[3][++len[3]]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		if(len[1]>n/2){
			sort(b[1]+1,b[1]+1+len[1]);
			for(i=1;i<=len[1]-n/2;i++)
				ans-=b[1][i];
		}
		if(len[2]>n/2){
			sort(b[2]+1,b[2]+1+len[2]);
			for(i=1;i<=len[2]-n/2;i++)
				ans-=b[2][i];
		}
		if(len[3]>n/2){
			sort(b[3]+1,b[3]+1+len[3]);
			for(i=1;i<=len[3]-n/2;i++)
				ans-=b[3][i];
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
