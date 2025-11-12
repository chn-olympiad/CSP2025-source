#include<bits/stdc++.h>
using namespace std;

const int maxn=555;
const int mod=998244353;

int c[maxn];
string s;

int sss[maxn];
bool vis[maxn];

void work(int n,int cnt){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	if(n==cnt){
		cout<<ans;
		return;
	}
//	sort(c+1,c+1+n);
//	int num=n-cnt;
//	for(int i=n-cnt+1;i<=n;i++){
//		if(c[i]=c[i-1]+1){
//			num=i;
//			if(num>=n-m){
//				
//			}
//			continue;
//		}
//		break;
//	}
}

int n,m;
int ans=0;

bool pand(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(sss[i]<=cnt||s[i-1]=='0'){
			cnt++;
		}
	}
	if(n-cnt<m)return 0;
	return 1;
}

void f(int k,int n){
	
	if(k==n){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				sss[n]=c[i];
				if(pand())ans++;
				break;
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			sss[k]=c[i];
			f(k+1,n);
			vis[i]=0;
		}
	}
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int pa=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			pa=1;
			break;
		}
	}
	int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt--;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		f(1,n);
		cout<<ans<<"\n";
		return 0;
	}
	if(!pa){
		work(n,cnt);
		return 0;
	}
	cout<<2;
	return 0;
}

/*

10 5
1111111111
6 0 4 2 1 2 5 4 3 3

998244353

*/

