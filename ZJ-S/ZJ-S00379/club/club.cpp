#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int T,n;
int a1[N],a2[N],a3[N];
int ans,cnt1,cnt2,cnt3;


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		ans=cnt1=cnt2=cnt3=0;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		priority_queue<pair<int,int>>p;
		cin>>n;
		int lim=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i=1;i<=n;i++){
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				cnt1++;
				ans+=a1[i];
				p.push(a1[i]-a2[i]);
				p.push(a1[i]-a3[i]); 
			}
			if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				cnt2++;
				ans+=a2[i];
			}
			if(a3[i]>=a1[i]&&a3[i]>=a2[i]){
				cnt3++;
				ans+=a3[i];
			}
		}
	}

	return 0;
}

