#include<iostream>
#include<cstdio> 

using namespace std;

const int N=1e6+10;

int n,m,k;
int a[N];
int ans=0;



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	cout<<ans<<endl;
	
	return 0;
}

