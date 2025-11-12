#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int a[N][10];
int maxn[N],mid[N]; 
int id[N];
int tot[10];
int b[N][10];
int ans;
int n;
void init(){
	ans=0;
	for(int i=1;i<=3;i++){
		tot[i]=0;
	}
	for(int i=1;i<=n;i++){
		maxn[i]=-1;
		mid[i]=-1;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn[i]){
					mid[i]=maxn[i];
					id[i]=j;
					maxn[i]=a[i][j];
				}
				else{
					if(mid[i]<a[i][j]){
						mid[i]=a[i][j];
					}
				}
			}
//			maxn[i]=max(a[i][1],a[i][2]);
//			mid[i]=min(a[i][1],a[i][2]);
//			if(a[i][1]>=a[i][2]){
//				id[i]=1;
//			}
//			else{
//				id[i]=2;
//			}
			ans+=maxn[i];
			tot[id[i]]++;
			b[id[i]][tot[id[i]]]=maxn[i]-mid[i];
//			if(maxn[i]!=max(a[i][1],a[i][2])||mid[i]!=min(a[i][1],a[i][2])){
//				cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<"***\n";
//			}
		} 
		int res=0;
		sort(b[1]+1,b[1]+tot[1]+1);
		sort(b[2]+1,b[2]+tot[2]+1);
//		cout<<tot[1]<<" "<<tot[2]<<"***\n";
//		for(int i=1;i<=tot[1];i++){
//			cout<<i<<" "<<b[1][i]<<"***\n";
//		}
		sort(b[3]+1,b[3]+tot[3]+1);
		bool flag=0;
		int k=0;
		for(int i=1;i<=3;i++){
			if(tot[i]>n/2){
				flag=1;
				k=i;
			}
		}
		if(!flag){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=tot[k]-n/2;i++){
			res+=b[k][i];
			ans-=b[k][i];
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
