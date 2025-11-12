#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,a[N][5],maxp,pos[N],cnt[3],cnts,minsc,compare[N];
void solve(){
	int sum=0;
	memset(cnt,0,sizeof cnt);
	cin>>n;//人数
	maxp=n/2;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++){
			cin>>a[i][j];//满意度
		}
	}
	for(int i=1;i<=n;i++) {
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) pos[i]=1,cnt[1]++;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) pos[i]=2,cnt[2]++;
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) pos[i]=3,cnt[3]++;
	}
	memset(compare,0,sizeof compare);
	if(cnt[2]>maxp){
		cnts=0;
		for(int i=1;i<=n;i++){
			if(pos[i]==2){
				compare[cnts]=a[i][2];
				cnts++;
			}
		}
		sort(compare,compare+cnts);
		minsc=compare[maxp];
		for(int i=1;i<=n;i++){
			int temp=0;
			if(pos[i]==2&&a[i][2]<minsc) {
				for(int j=i-1;j>=1;j--) temp=max(temp,max(max(a[i-j][1],a[i-j][3]),max(a[i][1],a[i][3])));
				if(temp==a[i][1]) pos[i]=1;
				else if(temp==a[i][3]) pos[i]=3;
				for(int j=i-1;j>=1;j--){
					if(temp==a[i-j][1]) pos[i-j]=1;
					else if(temp==a[i-j][3]) pos[i-j]=3;
				}
				
			}
		}
	}
	else if(cnt[1]>maxp){
		cnts=0;
		for(int i=1;i<=n;i++){
			if(pos[i]==1){
				compare[cnts]=a[i][1];
				cnts++;
			}
		}
		sort(compare,compare+cnts);
		minsc=compare[maxp];
		for(int i=1;i<=n;i++){
			int temp=0;
			if(pos[i]==1&&a[i][1]<minsc) {
				for(int j=i-1;j>=1;j--) temp=max(temp,max(max(a[i-j][2],a[i-j][3]),max(a[i][2],a[i][3])));
				if(temp==a[i][2]) pos[i]=2;
				else if(temp==a[i][3]) pos[i]=3;
				for(int j=i-1;j>=1;j--){
					if(temp==a[i-j][2]) pos[i-j]=2;
					else if(temp==a[i-j][3]) pos[i-j]=3;
				}
			}

		}
	}
	else if(cnt[3]>maxp){
		cnts=0;
		for(int i=1;i<=n;i++){
			if(pos[i]==3){
				compare[cnts]=a[i][3];
				cnts++;
			}
		}
		sort(compare,compare+cnts);
		minsc=compare[maxp];
		for(int i=1;i<=n;i++){
			int temp=0;
			if(pos[i]==3&&a[i][3]<minsc) {
				for(int j=i-1;j>=1;j--) temp=max(temp,max(max(a[i-j][1],a[i-j][2]),max(a[i][1],a[i][2])));
				if(temp==a[i][1]) pos[i]=1;
				else if(temp==a[i][2]) pos[i]=2;
				for(int j=i-1;j>=1;j--){
					if(temp==a[i-j][1]) pos[i-1]=1;
					else if(temp==a[i-j][2]) pos[i-1]=2;
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		sum+=a[i][pos[i]];
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
