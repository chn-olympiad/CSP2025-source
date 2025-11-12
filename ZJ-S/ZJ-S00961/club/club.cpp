#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t;
int n,sum;
int used[N];
int bu_num[4];

struct node{
	int x;
	int bu;
	int point;
}q[N*3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(used,0,sizeof used);
		memset(bu_num,0,sizeof bu_num);
		sum=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>q[3*i+j-3].x;
				q[3*i+j-3].point=i;
				q[3*i+j-3].bu=j;
			}
		}
		
		for(int i=1;i<=3*n;i++){
			for(int j=i+1;j<=3*n;j++){
				if(q[i].x<q[j].x){
					swap(q[i],q[j]);
				}
			}
		}
		
		for(int i=1;i<=3*n;i++){
			if(used[q[i].point]==0 && bu_num[q[i].bu]+1<=n/2){
				sum+=q[i].x;
				used[q[i].point]=1;
				bu_num[q[i].bu]++;
			}
		}
		
		cout<<sum<<endl;
	}
	return 0;
}

