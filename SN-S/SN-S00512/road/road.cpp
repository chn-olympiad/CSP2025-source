#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,cnt,minn=0x7f7f7f7f,sum,f,flag[100005],t[15][100005],arr[10005][10005];
void dfs(long long x){
	if(cnt==n){
		minn=min(minn,sum);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(x!=i and flag[i]==0){
			flag[i]=1;
			sum+=arr[x][i];
			cnt++;
			dfs(i);
			cnt--;
			sum-=arr[x][i];
			flag[i]=0;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i!=j) arr[i][j]=0x7f7f7f7f;
		}
	}
	for(long long i=1;i<=m;i++){
		cin>>a>>b>>c;
		arr[a][b]=c;
		arr[b][a]=c;
	}
	for(long long i=1;i<=k;i++){
		cin>>t[i][0];
		for(long long j=1;j<=n;j++) cin>>t[i][j];
	}
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			for(long long p=1;p<=k;p++){
				arr[i][j]=min(arr[i][j],t[p][0]+t[p][i]+t[p][j]);
				arr[j][i]=min(arr[i][j],t[p][0]+t[p][i]+t[p][j]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		flag[i]=1;
		sum=0;
		cnt=1;
		dfs(i);
	}
	cout<<minn;
	return 0;
}
