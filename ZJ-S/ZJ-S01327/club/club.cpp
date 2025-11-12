#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],ans,sum[5],k,b[50005],x,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int o=1;o<=t;o++){
		sum[1]=sum[2]=sum[3]=ans=x=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			k=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=k;
			if(a[i][1]==k){
				sum[1]++;
			}
			else if(a[i][2]==k){
				sum[2]++;
			}
			else{
				sum[3]++;
			}
		}
		for(int i=1;i<=3;i++){
			if(sum[i]>n/2){
				c=i;
				for(int j=1;j<=n;j++){
					k=max(a[j][1],max(a[j][2],a[j][3]));
					if(a[j][i]==k){
						b[++x]=k-max(a[j][i%3+1],a[j][(i+1)%3+1]);
					}
				}
			}
		}
		sort(b+1,b+x+1);
		for(int i=1;i<=sum[c]-n/2;i++){
			ans-=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
