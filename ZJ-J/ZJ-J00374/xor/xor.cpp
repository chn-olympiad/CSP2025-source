#include<bits/stdc++.h>
#define N 500005
using namespace std;
int a[N],n,k,len,dp[N],l=1;
unordered_map<int,vector<int> >ma;
struct Node{
	int x,y;
}b[N];
bool cmp(Node a,Node b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
		ma[a[i]].push_back(i);
	}
	for(int i=0;i<=n;i++){
		int pur=a[i]^k;
		if(ma[pur].size()){
			int p=/*ma[pur][*/lower_bound(ma[pur].begin(),ma[pur].end(),i+1)-(ma[pur].begin())/*]*/,p2;
//			for(int j=0;j<ma[pur].size();j++){
//				if(ma[pur][j]>i){
//					p2=ma[pur][j];
//					break;
//				}
//			}
//			cout<<p2<<" "<<p<<"\n";
//			cout<<i+1<<" "<<"OK\n";
			if(p!=ma[pur].size()){
				b[++len].x=i+1;
				b[len].y=ma[pur][p];
			}
		}
	}
	stable_sort(b+1,b+1+len,cmp);
//	for(int i=1;i<=len;i++){
//		cout<<"["<<b[i].x<<","<<b[i].y<<"]\n";
//	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		while(b[l].y==i){
			dp[i]=max(dp[i],dp[b[l].x-1]+1);
			l++;
		}
		//cout<<dp[i]<<" ";
	}
	cout/*<<"\n"*/<<dp[n];
	return 0;
}
/*
4 0
2 1 0 3
*/