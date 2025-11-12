#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > a;
int cnt[3],sum;
bool cmp(vector<int>& x,vector<int>& y)
{
	int maxx=max(x[0],max(x[1],x[2])),maxy=max(y[0],max(y[1],y[2])),secx=min(x[0],min(x[1],x[2]));
	for(int i=0;i<3;i++){
		if(x[i]!=maxx&&x[i]!=secx){
			secx=x[i];
			break;
		}
	}
	return maxx>maxy&&maxx-secx>maxy;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int mid=n/2;
		a.resize(n,vector<int>(3));
		cnt[0]=0;cnt[1]=0;cnt[2]=0;
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		sort(a.begin(),a.end(),cmp);
		int k;
		sum=0;
		for(i=0;i<n;i++){
			k=-1;
			for(j=0;j<3;j++){
				if(k<0&&cnt[j]<mid){
					k=j;
				}else{
					int &maxx=a[i][k];
					if(cnt[j]<mid&&a[i][j]>maxx)k=j;
				}
			}
			sum+=a[i][k];
			cnt[k]++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
