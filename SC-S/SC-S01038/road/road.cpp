#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int a[N][5],b[N][5],maxn[N][5];
bool f[N];
int t;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,cnt[3]={0,0,0};
		cin>>n;
		int h=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1]=a[i][1];
			b[i][2]=a[i][2];
			b[i][3]=a[i][3];
			sort(&b[i][0]+1,&b[i][0]+4);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(a[i][j]==b[i][1]){
					maxn[i][1]=j;
				}
				else if(a[i][j]==b[i][2]){
					maxn[i][2]=j;
				}
				else if(a[i][j]==b[i][3]){
					maxn[i][3]=j;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(cnt[1]+1<=n/2&&f[i]==0{
				f[i]=1;
				cnt[1]+=1;
				ans+=b[i][1];
			}
			else if(cnt[2]+1<=n/2&&f[i]==0){
				f[i]=1;
				cnt[2]+=1;
				ans+=b[i][1];
			}
			else if(cnt[3]+1<=n/2&&f[i]==0){
				f[i]=1;
				cnt[3]+=1;
				ans+=b[i][3];
			}
		}
		cout<<ans<<"\n";
	}
}