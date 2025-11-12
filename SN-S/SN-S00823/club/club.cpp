#include<iostream>
#include<algorithm>

using namespace std;

int n=0,T=0,text[5]= {0};
long long ans=0,now=0;
bool check[100005]= {0};
int m[100005][3]= {0};

void dfs(int i,int j,int depth) {
	if(check[i]) {
		return;
	}
	if(text[j]>=(n/2)) {
		return;
	}
	now+=m[i][j];
	check[i]=1;
	text[j]+=1;
	if(depth==n) {
		ans=max(now,ans);
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=2; j++) {
				dfs(i,j,depth+1);
			}
		}
	}
	now-=m[i][j];
	check[i]=0;
	text[j]-=1;
	return;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		now=0;
		for(int i=1; i<=n; i++) {
			cin>>m[i][0]>>m[i][1]>>m[i][2];
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=2; j++) {
				dfs(i,j,1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
