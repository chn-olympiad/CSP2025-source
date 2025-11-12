#include<bits/stdc++.h>
using namespace std;
int T,n,a[100011][4],d[100011];
long long sum=0,f[100011];
priority_queue<int>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		sum=0;
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			int x=max({a[i][1],a[i][2],a[i][3]});
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])c1++,d[i]=1;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])c2++,d[i]=2;
			else c3++,d[i]=3;
			for(int j=1;j<=3;j++)a[i][j]-=x;
			sum+=x;
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			printf("%lld\n",sum);
			continue;
		}
		int u=-1,c=max({c1,c2,c3});
		if(c1>n/2)u=1;
		else if(c2>n/2)u=2;
		else if(c3>n/2)u=3;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)
			if(d[i]==u){
				int mx=INT_MIN;
				for(int j=1;j<=3;j++)
					if(j!=u)mx=max(mx,a[i][j]);
				q.push(mx);
			}
		while(q.size()>n/2)sum+=q.top(),q.pop();
		printf("%lld\n",sum);
	}
	return 0;
}
