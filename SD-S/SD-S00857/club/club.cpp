#include<bits/stdc++.h>
//#define int long long
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ls(x)(x<<1)
#define rs(x)(x<<1|1)
#define mid(l,r)((l+r)>>1)
#define fclose buyaojiafclose
using namespace std;
const int maxn=1e5+37;
struct node{
	int num,id;
};
bool cmp(node a,node b){
	return a.num>b.num;
}
node a[maxn][4];
int n;
struct node2{
	int num,id,sum;
	bool operator <(const node2 &x)const{//ธ๙ะก 
		return x.num<num;
	}
};

priority_queue<node2>q[4];
void sol(){
	for(int i=1;i<=n;i++){
		q[a[i][1].id].push((node2){a[i][1].num-a[i][2].num,i,a[i][1].num});
	}
	for(int i=1;i<=3;i++){
		if((int)(q[i].size())>n/2){
			while((int)(q[i].size())>n/2){
				int fro=q[i].top().id;
				q[i].pop();
				q[a[fro][2].id].push((node2){a[fro][2].num-a[fro][3].num,fro,a[fro][2].num});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty()){
			ans+=q[i].top().sum;
			q[i].pop();
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	FST;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].num>>a[i][2].num>>a[i][3].num;
			for(int j=1;j<=3;j++)a[i][j].id=j;
			sort(a[i]+1,a[i]+3+1,cmp);
		}
		sol();
	}
	
	return 0;
} 
