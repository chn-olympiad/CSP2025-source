#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int T,n,ct[3],id[N];
LL a[N][3],ans;
priority_queue<LL>dl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		while(dl.size())dl.pop();
		for(int i=0;i<3;i++)ct[i]=0;
		for(int i=1;i<=n;i++){
			id[i]=0;
			for(int j=0;j<3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]>a[i][id[i]])id[i]=j;
			}
			++ct[id[i]],ans+=a[i][id[i]];
		}
		for(int i=0;i<3;i++){
			if(ct[i]>n/2){
				int ls=ct[i]-n/2;
				for(int j=1;j<=n;j++){
					if(id[j]!=i)continue;
					LL mx=(i==0?1:0);
					for(int k=0;k<3;k++){
						if(i==k)continue;
						if(a[j][k]>a[j][mx])mx=k;
					}
					dl.push(a[j][mx]-a[j][id[j]]);
				}
				while(ls--){
					ans+=dl.top(),dl.pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
