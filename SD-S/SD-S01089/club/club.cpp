#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

int t;
bool A=true;
bool B=true;

const int maxn=100;
int n;
int a[maxn][5];
int f[maxn][50][50][50];

bool cmp(int a,int b){
	return a>b;
}

void solve(){
//¶à²â  
	memset(a,0,sizeof a);
	memset(f,0,sizeof f);
	
				
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]!=0||a[i][3]!=0)A=false;
		if(a[i][3]!=0)B=false;
	}
	if(A==true){
		vector<int> vec;
		for(int i=1;i<=n;i++){
			vec.push_back(a[i][1]);
		}
		sort(vec.begin(),vec.end(),cmp);
		int ans=0;
		int b=0;
		for(int it:vec){
			ans+=it;
			b++;
			if(b==n/2)break;
		}
		cout<<ans<<endl;
		return;
	}
	f[1][1][0][0]=a[1][1];
	f[1][0][1][0]=a[1][2];
	f[1][0][0][1]=a[1][3];
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				for(int s=0;s<=n/2;s++){
					if(j>0){
						f[i][j][k][s]=max(f[i-1][j-1][k][s]+a[i][1],f[i][j][k][s]);
					}
					if(k>0){
						f[i][j][k][s]=max(f[i-1][j][k-1][s]+a[i][2],f[i][j][k][s]);
					}
					if(s>0){
						f[i][j][k][s]=max(f[i-1][j][k][s-1]+a[i][3],f[i][j][k][s]);
					}
					if(i==n){
						ans=max(ans,f[i][j][k][s]);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
