#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int a[maxn][3];

int cnt[3];
int max_per_bu;
int n;
int maxnm;
long long sum=0;

void dfs(int i){
	if(cnt[0]>max_per_bu)return;
	if(cnt[2]>max_per_bu)return;
	if(cnt[1]>max_per_bu)return;
	if(i==n){
		if(maxnm<sum)maxnm=sum;
	}
	cnt[0]++;
	sum+=a[i][0];
	dfs(i+1);
	cnt[0]--;
	sum-=a[i][0];
	cnt[1]++;
	sum+=a[i][1];
	dfs(i+1);
	cnt[1]--;
	sum-=a[i][1];
	cnt[2]++;
	sum+=a[i][2];
	dfs(i+1);
	cnt[2]--;
	sum-=a[i][2];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		maxnm=0;
		//bool is_=false;
		cin>>n;
		max_per_bu=n/2;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		/*for(int i=0;i<n;i++){
			if(a[i][2]!=0||a[i][1]!=0){
				is_=true;
				break;
			}
		}
		if(!is_){
			int b[maxn];
			for(int i=0;i<n;i++){
				b[i]=a[i][0];
			}
			sort(b,b+n);
			long long summ=0;
			for(int i=0;i<n/2;i++){
				summ+=b[i];
			}
			cout<<summ<<"\n";
			continue;
		}*/
		dfs(0);
		cout<<maxnm<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
