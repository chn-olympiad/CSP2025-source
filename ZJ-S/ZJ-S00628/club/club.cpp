#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int _,n,a[N][3],p[3],b[N],s;
int Max(int a[]){
	return a[0]>a[1]?a[0]>a[2]?0:2:a[1]>a[2]?1:2;
}
priority_queue<int> q;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		cin>>n;
		s=p[0]=p[1]=p[2]=0;
		while(!q.empty())
			q.pop();
		for(int i=1,x;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2],
			x=Max(a[i]),
			s+=a[i][x],
			p[x]++;
		int x=Max(p);
		if(p[x]>n/2){
			for(int i=1;i<=n;i++)
				if(Max(a[i])==x)
					q.push(-min(a[i][x]-a[i][(x+1)%3],a[i][x]-a[i][(x+2)%3]));
			while(p[x]>n/2)
				p[x]--,
				s+=q.top(),
				q.pop();
			cout<<s<<'\n';
		}else
			cout<<s<<'\n';
	}
	return 0;
}

