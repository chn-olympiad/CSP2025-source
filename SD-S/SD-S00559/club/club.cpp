//by SmileMask
#include<bits/stdc++.h>
using namespace std;

namespace SmileMask{
	#define rd read()
	int read(){
		int num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}
		while(isdigit(ch)){
			num=(num<<3)+(num<<1)+ch-'0';
			ch=getchar();
		}
		return num*sign;
	}
	
	const int N=1e5+10;
	
	pair<int,int> a[N][3];
	
	int ans;
	
	int n; 
	
	priority_queue <int> q[3];

	void Main(){
		n=rd,ans=0;
		for(int i=0;i<3;i++){
			while(q[i].size())
				q[i].pop();
		}
		for(int i=1;i<=n;i++){
			a[i][0]={rd,0},a[i][1]={rd,1},a[i][2]={rd,2};
			sort(a[i],a[i]+3);
			q[a[i][2].second].push(a[i][1].first-a[i][2].first);
			ans+=a[i][2].first;
			if(q[a[i][2].second].size()>n/2)
				ans+=q[a[i][2].second].top(),q[a[i][2].second].pop();
		}
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) SmileMask::Main();
	return 0;
}


