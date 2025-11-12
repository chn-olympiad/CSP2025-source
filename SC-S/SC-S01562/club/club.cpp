#include<bits/stdc++.h>
#define fi first
#define se second 
#define endl "\n"
#define int long long 
using namespace std;
const int maxn=1e5+10;
int t;
int a[maxn][4],b[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cin>>t;
	while(t--){
		memset(a,0,sizeof a);memset(b,0,sizeof b);int n;int sum=0;cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];}
		int cnt_a=0,cnt_b=0,cnt_c=0;
		for(int i=1;i<=n;i++){
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			if(x==a[i][1]){b[i]=1;cnt_a++;sum+=x;}
			else if(x==a[i][2]){b[i]=2;cnt_b++;sum+=x;}
			else {b[i]=3;cnt_c++;sum+=x;}
		}
//		cout<<cnt_a<<" "<<cnt_b<<" "<<cnt_c<<endl;
		while(cnt_a>n/2 || cnt_b>n/2 || cnt_c>n/2){
			if(cnt_a>n/2){
				int k1=0,min_x1=INT_MAX;
				for(int i=1;i<=n;i++){
					if(b[i]==1){
						if(min_x1>a[i][1]-a[i][2]){min_x1=min(min_x1,a[i][1]-a[i][2]);k1=i;}
					}
				}
				int k2=0,min_x2=INT_MAX;
				for(int i=1;i<=n;i++){
					if(b[i]==1){
						if(min_x2>a[i][1]-a[i][3]){min_x2=min(min_x2,a[i][1]-a[i][3]);k2=i;}
					}
				}
				if(min_x1>=min_x2 && cnt_c+1<=n/2){cnt_a--;cnt_c++;sum-=min_x2;b[k2]=3;}
				else {cnt_a--;cnt_b++;sum-=min_x1;b[k1]=2;}
			}
			else if(cnt_b>n/2){
				int k1=0,min_x1=INT_MAX;
					
				for(int i=1;i<=n;i++){
					if(b[i]==2){
						if(min_x1>a[i][2]-a[i][1]){min_x1=min(min_x1,a[i][2]-a[i][1]);k1=i;}
					}
				}
				int k2=0,min_x2=INT_MAX;
				for(int i=1;i<=n;i++){
					if(b[i]==2){
						if(min_x2>a[i][2]-a[i][3]){min_x2=min(min_x2,a[i][2]-a[i][3]);k2=i;}
					}
				}
				if(min_x1>=min_x2 && cnt_c+1<=n/2){cnt_b--;cnt_c++;sum-=min_x2;b[k2]=3;}
				else {cnt_b--;cnt_a++;sum-=min_x1;b[k1]=1;}
			}
			else if(cnt_c>n/2){
				int k1=0,min_x1=INT_MAX;
				for(int i=1;i<=n;i++){
					if(b[i]==3){
						if(min_x1>a[i][3]-a[i][1]){min_x1=min(min_x1,a[i][3]-a[i][1]);k1=i;}
					}
				}
				int k2=0,min_x2=INT_MAX;
				for(int i=1;i<=n;i++){
					if(b[i]==3){
						if(min_x2>a[i][3]-a[i][2]){min_x2=min(min_x2,a[i][3]-a[i][2]);k2=i;}
					}
				}
				if(min_x1>=min_x2 && cnt_b+1<=n/2){cnt_c--;cnt_b++;sum-=min_x2;b[k2]=2;}
				else {cnt_c--;cnt_a++;sum-=min_x1;b[k1]=1;}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][b[i]];
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<endl;
//		}
//		cout<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/