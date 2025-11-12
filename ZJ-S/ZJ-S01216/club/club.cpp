#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5;
long long t;
long long n;
long long d[maxn+1][5],ans;
long long x[maxn+1];
long long DFS(long long now,long long a,long long b,long long c,long long sum){
	long long ret=0;
	if(now>=n){
		return sum;
	}
	if(a<n/2){
		ret=max(ret,DFS(now+1,a+1,b,c,sum+d[now+1][1]));
	}
	if(b<n/2){
		ret=max(ret,DFS(now+1,a,b+1,c,sum+d[now+1][2]));
	}
	if(c<n/2){
		ret=max(ret,DFS(now+1,a,b,c+1,sum+d[now+1][3]));
	}
	return ret;
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
srand(time(0));
cin>>t;
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>d[i][j];
		}
	}
	ans=0;
	if(n<=10){
		ans=max(ans,DFS(1,1,0,0,d[1][1]));
		ans=max(ans,DFS(1,0,1,0,d[1][2]));
		ans=max(ans,DFS(1,0,0,1,d[1][3]));
		cout<<ans<<endl;
	}
	else{
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			if(d[i][2]!=0){
				flag1=false;
			}
			if(d[i][3]!=0){
				flag2=false;
			}
		}
		if(flag1&&flag2){
			for(int i=1;i<=n;i++){
				x[i]=d[i][1];
			}
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=x[i];
			}
			cout<<ans<<endl;
			continue;
		}
	}
}
return 0;
}
