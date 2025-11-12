#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,a[N][4],sum=0,cnt=0,maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i==j){
					continue;
				}
				sum=a[1][i]+a[2][j];
				cnt=a[1][j]+a[2][i];
				maxn=max(maxn,sum);
				maxn=max(maxn,cnt);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
