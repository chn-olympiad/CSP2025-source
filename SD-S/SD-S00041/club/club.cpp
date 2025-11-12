#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define x first
#define y second
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],b[N],c[N],bk[N],bk2[4],ans;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int st,int sum){
	if(st==n+1){
		//cout<<st<<"---"<<sum<<"---"<<endl; 
		ans=max(ans,sum);
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(bk[i]==0){
					bk[i]=1;
					bk2[j]++;
					//cout<<st<<"---"<<sum<<"---"<<i<<"<-i --- "<<j<<"<-j --- "<<a[i][j]<<endl; 
					//cout<<j<<"---"<<bk2[j]<<"-<<"<<endl;
					if(bk2[j]<=n/2)dfs(st+1,sum+a[i][j]);
					bk2[j]--;
					bk[i]=0;
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>t;
	while(t--){
		for(int i=1;i<=N-5;i++)for(int j=1;j<=3;j++)a[i][j]=0;
		for(int i=1;i<=N-5;i++)bk[i]=0;
		for(int i=1;i<=3;i++)bk2[i]=0;
		ans=0;
		
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1],c[i]=a[i][2];
		}
		
		if(n<=200)dfs(1,0);
		else{
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

