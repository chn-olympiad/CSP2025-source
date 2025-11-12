#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N][4];
int mx[N];
int buckets[4];

struct node{
	ll delta,val,idx;
	friend bool operator<(node x,node y){
		return x.delta<y.delta;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		memset(mx,0,sizeof(mx));
		memset(buckets,0,sizeof(buckets));
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) mx[i]=1;
			else if(a[i][2]>=a[i][3]) mx[i]=2;
			else mx[i]=3;
			buckets[mx[i]]++;
		}
		
		bool finish=true;
		int leq=0;
		for(int i=1;i<=3;i++){
			if(buckets[i]>n/2){
				finish=false;
				leq=i;
				break;
			}
		}
		
		if(finish){
			ll res=0;
			for(int i=1;i<=n;i++){
				res+=a[i][mx[i]];
			}
			cout<<res<<"\n";
		}else{
//			cout<<leq<<"\n";
			priority_queue<node > pq;
			for(int i=1;i<=n;i++){
				if(mx[i]==leq){
					int val1=-1,val2=-1;
					int idx1=0,idx2=0;
					for(int j=1;j<=3;j++){
						if(j!=leq){
							if(val1==-1)
								val1=a[i][j],idx1=j;
							else
								val2=a[i][j],idx2=j;
						}
					}
					if(val1>val2)
						pq.push({a[i][leq]-val1,val1,i});
					else
						pq.push({a[i][leq]-val2,val2,i});
				}
			
			}
			
			int num=0;
			ll sum=0;
			while(num<n/2){
				node tp=pq.top();
//				cout<<tp.delta<<" "<<tp.val<<" "<<tp.idx<<"\n";
				pq.pop();
				int i=tp.idx;
				num++;
				sum+=a[i][leq];
			}
			
			while(!pq.empty()){
				node tp=pq.top();
//				cout<<tp.delta<<" "<<tp.val<<" "<<tp.idx<<"\n";
				pq.pop();
				ll v=tp.val;
				sum+=v;
			}
			
			for(int i=1;i<=n;i++){
				if(mx[i]!=leq)
					sum+=a[i][mx[i]];
			}
			cout<<sum<<"\n";
		}
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

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
