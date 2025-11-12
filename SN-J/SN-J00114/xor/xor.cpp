#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
int qzh[500005];
struct node{
	pair<int,int> x;
}b[500005];
 
bool cmp(node x,node y){
	return x.x.second<y.x.second;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
	}int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			//cout<<(qzh[j]^qzh[i-1])<<' ';
			if((qzh[j]^qzh[i-1])==k){
				cnt++;
				b[cnt].x={i,j};
				
				break;
			}
		}
		//cout<<'\n';
	}
	sort(b+1,b+1+cnt,cmp);
	int last=0,ans=0;
	for(int i=1;i<=cnt;++i){
		//cout<<b[i].x.first<<' '<<b[i].x.second<<'\n';
		if(b[i].x.first>last){
			last=b[i].x.second;
			ans++;
		}
	}
	/*
	for(int i=1;i<=n;++i){
		cout<<qzh[i]<<' ';
	}*/
	cout<<ans;
	return 0;
} 
