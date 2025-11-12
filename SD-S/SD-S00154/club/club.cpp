#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5],b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int _1=0,_2=0,_3=0,tot=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
				_3++,ans+=a[i][3];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				_2++,ans+=a[i][2];
			else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				_1++,ans+=a[i][1]; 
		}
		if(_1>n/2){
			for(int i=1;i<=n;i++)
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
					b[++tot]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		else if(_2>n/2){
			for(int i=1;i<=n;i++)
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
					b[++tot]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		else if(_3>n/2){
			for(int i=1;i<=n;i++)
				if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
					b[++tot]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
		}
		sort(b+1,b+tot+1);
		for(int i=1;i<=tot-n/2;i++)
			ans-=b[i];
		cout<<ans<<'\n';
	}
	return 0;
}
