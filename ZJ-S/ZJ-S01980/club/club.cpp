#include<bits/stdc++.h>
using namespace std;
long long T,n,s,a[100010][5],b[100010][5],c[100010],mx[100010],ans,t,d[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			for(int k=1;k<=3;k++)b[j][k]=a[j][k];
			sort(b[j]+1,b[j]+4);
			ans+=b[j][3];
			for(int k=1;k<=3;k++){
				if(a[j][k]==b[j][3])mx[k]++;
				c[j]=b[j][3]-b[j][2];
			}
		}
		for(int j=1;j<=3;j++){
			if(mx[j]>(n/2)){
				for(int k=1;k<=n;k++){
					if(a[k][j]==b[k][3]){
						d[++t]=c[k];
					}
				}
				sort(d+1,d+t+1);
				for(int k=1;k<=mx[j]-(n/2);k++)ans-=d[k];
				break;
			}
		}
		cout<<ans<<'\n';
		ans=0,t=0;
		memset(mx,0,sizeof(mx));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
	}
	return 0;
}
