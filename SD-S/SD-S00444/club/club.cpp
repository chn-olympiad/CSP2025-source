#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>

#define ll long long

using namespace std;

const int N=100005;
int n,t,a[N][4],cnt[4],b,sum,los;
struct stu{
	int data;
	int index;
}c[N][3],d[N];

bool cmp(stu x,stu y){
	return x.data>y.data;
}

int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(cnt,0,sizeof(cnt));
		sum=0;los=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			b=0;
			a[i][0]=0x3fffffff;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][b]>a[i][j])b=j;
			}
			for(int j=1;j<=3;j++){
				if(j==b)continue;
				if(c[i][1].index==0){
					c[i][1].data=a[i][j];
					c[i][1].index=j;
				}
				else {
					c[i][2].data=a[i][j];
					c[i][2].index=j;
				}
			}
			if(c[i][2].data>c[i][1].data)swap(c[i][2],c[i][1]);
			sum+=c[i][1].data;
			d[i].data=c[i][1].data-c[i][2].data;
			d[i].index=i;
		}
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[c[d[i].index][1].index]>=n/2){
				cnt[c[d[i].index][2].index]++;
				los+=d[i].data;
			}
			else {
				cnt[c[d[i].index][1].index]++;
			}
		}
		cout<<sum-los<<'\n';
	}
	
	return 0;
}

