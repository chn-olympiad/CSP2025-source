#include<bits/stdc++.h>
using namespace std;
int a[1000010],cou[15][100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>a[i];
	}bool flag=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>cou[i][j];
			if(cou[i][j]!=0)flag=1;
		}
	}if(!flag)cout<<'0';
	else{
		long long minn=0x3f3f3f3f,sum=0;
		for(int i=1;i<=m;i++){
			sum+=a[i];
		}if(sum<minn)minn=sum;
		for(int i=1;i<=k;i++){
			sum=0;
			for(int j=1;j<=n+1;j++)sum+=cou[i][j];
			minn=min(minn,sum);
		}cout<<minn;
	}
	return 0;
}