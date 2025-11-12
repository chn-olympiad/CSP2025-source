#include <bits/stdc++.h>

using namespace std;

int n;
int t;
int a1,a2,a3;

int ans=0;

struct peo{
	int a[4];
	bool c=0;
};

peo p[100001];

void dfs(int s1,int s2,int s3,int ansn,int ri,int rj){
	ansn+=p[ri].a[rj];
	ans = max(ans,ansn);
	if(ri>=n)return;
	cout<<ri<<" "<<rj<<endl;
	//cout<<1;
	if(s1<n/2){	
		dfs(s1+1,s2,s3,ansn,ri+1,1);
	}
	if(s2<n/2){
		dfs(s1,s2+1,s3,ansn,ri+1,2);
	}
	if(s3<n/2){
		dfs(s1,s2,s3+1,ansn,ri+1,3);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j = 0;j < t;j++){
		cin>>n;
		
		for(int k = 1;k <= n;k++){
			cin>>p[k].a[1]>>p[k].a[2]>>p[k].a[3];
		}
		//cout<<a1<<" "<<a2<<" "<<a3<<endl;
		//cout<<n<<endl;
		dfs(0,0,0,0,0,0);
		cout<<ans<<endl;
		ans = 0;
		return 0;
	}
	return 0;
}
