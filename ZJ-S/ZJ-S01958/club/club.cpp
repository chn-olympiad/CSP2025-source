#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][13],ans,cnt[13],len[13],l[13][100010];
void f(int x){
	sort(l[x]+1,l[x]+1+len[x]);
	for(int i=1;i<=cnt[x]-n/2;++i){
		ans-=l[x][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=len[1]=len[2]=len[3]=ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]>a[i][2]){
				if(a[i][1]>a[i][3]){
					cnt[1]++;
					ans+=a[i][1];
					if(a[i][2]>a[i][3])l[1][++len[1]]=a[i][1]-a[i][2];
					else l[1][++len[1]]=a[i][1]-a[i][3];
				}
				else{
					cnt[3]++;
					ans+=a[i][3];
					l[3][++len[3]]=a[i][3]-a[i][1];
				}
			}
			else{
				if(a[i][2]>a[i][3]){
					cnt[2]++;
					ans+=a[i][2];
					if(a[i][1]>a[i][3])l[2][++len[2]]=a[i][2]-a[i][1];
					else l[2][++len[2]]=a[i][2]-a[i][3];
				}
				else{
					cnt[3]++;
					ans+=a[i][3];
					l[3][++len[3]]=a[i][3]-a[i][2];
				}
			}
		}
		if(cnt[1]>n/2){
			f(1);
		}
		else if(cnt[2]>n/2){
			f(2);
		}
		else if(cnt[3]>n/2){
			f(3);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
