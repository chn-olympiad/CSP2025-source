#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
/*
struct node{
	int v;
	long long w;
};
vector<node>a[10005];
*/ 
long long a[7000][7000];
long long cz[10005];//ji lu cun zhuang
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		/*
		node one;
		one.w=z;
		if
		a[x].push_back(one);
		*/
		if(z<a[x][y]){
			a[x][y]=z;
			a[y][x]=z;
		}
	}
	for(int i=1;i<=k;i++){
		int changshu;
		cin>>changshu;
		for(int j=1;j<=n;j++){
			cin>>cz[j];
		}
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				int lsans=cz[j]+cz[p]+changshu;
				if(lsans<a[j][p]){
					a[j][p]=lsans;
					a[p][j]=lsans;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cz[i]=a[1][i];
	//	cout<<cz[i]<<' ';
		a[i][1]=1e18;
	}
//	cout<<endl<<endl;;
	for(int j=1;j<n;j++){
		long long minx=1e18,mina=0;
		for(int i=1;i<=n;i++){
			if(cz[i]<minx){
			//	cout<<i<<' ';
				minx=cz[i];
				mina=i;
			//	cout<<minx<<' '<<mina<<' '<<' '<<' ';
			}
		}
		//zhao zui xiao;
		ans+=cz[mina];
	//	cout<<cz[mina]<<endl;
		cz[mina]=1e18;
		for(int i=1;i<=n;i++){
			if(cz[i]>a[mina][i]){
				cz[i]=a[mina][i];//gengxin
			}
			a[i][mina]=1e18;
		}
	}
	cout<<ans;
	return 0;
}
