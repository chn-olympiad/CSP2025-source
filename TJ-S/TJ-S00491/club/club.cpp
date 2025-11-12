#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct person{
	int po[4],best[3],better[2],worse;
}a[100005];
bool cmp(person x,person y){
	return x.po[x.best[0]]<y.po[y.best[0]];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].po[1]>>a[i].po[2]>>a[i].po[3];
		}
		for(int i=1;i<=n;i++){
			if(a[i].po[1]>=a[i].po[2]&&a[i].po[1]>=a[i].po[3]){
				a[i].best[0]=1;
				if(a[i].po[1]==a[i].po[2]){
					a[i].best[1]=2;
					if(a[i].po[1]==a[i].po[3]){
						a[i].best[2]=3;
					}
					else{
						a[i].better[0]=3;
					}
				}
				else if(a[i].po[2]<a[i].po[1]){
					a[i].better[0]=2;
					if(a[i].po[3]<a[i].po[2]){
						a[i].worse=3;
					}
					else{
						a[i].better[1]=3;
					}
				}
			}
			else if(a[i].po[2]>=a[i].po[1]&&a[i].po[2]>=a[i].po[3]){
				a[i].best[0]=2;
				if(a[i].po[2]==a[i].po[1]){
					a[i].best[1]=1;
					if(a[i].po[2]==a[i].po[3]){
						a[i].best[2]=3;
					}
					else{
						a[i].better[0]=3;
					}
				}
				else if(a[i].po[1]<a[i].po[2]){
					a[i].better[0]=1;
					if(a[i].po[3]<a[i].po[1]){
						a[i].worse=3;
					}
					else{
						a[i].better[1]=3;
					}
				}
			}
			else{
				a[i].best[0]=3;
				if(a[i].po[3]==a[i].po[2]){
					a[i].best[1]=2;
					if(a[i].po[3]==a[i].po[1]){
						a[i].best[2]=1;
					}
					else{
						a[i].better[0]=1;
					}
				}
				else if(a[i].po[2]<a[i].po[3]){
					a[i].better[0]=2;
					if(a[i].po[1]<a[i].po[2]){
						a[i].worse=1;
					}
					else{
						a[i].better[1]=1;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			int choose=0;
			if(cnt[a[i].best[0]]+1<=n/2){
				choose=a[i].best[0];
			}
			else if(a[i].best[1]!=0&&cnt[a[i].best[1]]+1<=n/2){
				choose=a[i].best[1];
			}
			else if(a[i].best[2]!=0&&cnt[a[i].best[2]]+1<=n/2){
				choose=a[i].best[2];
			}
			else if(cnt[a[i].better[0]]+1<=n/2){
				choose=a[i].better[0];
			}
			else if(a[i].better[1]!=0&&cnt[a[i].better[1]]+1<=n/2){
				choose=a[i].better[1];
			}
			else{
				choose=a[i].worse;
			}
			cnt[0]+=a[i].po[choose];
			cnt[choose]++;
		}
		cout<<cnt[0]<<'\n';
	}
	//我的脑子炸了！ =(
	return 0;
}
