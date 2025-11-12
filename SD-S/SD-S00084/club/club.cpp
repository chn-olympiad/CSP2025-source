#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;

int T,n;
int a[N];
long long ans=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
//		int max_num=n/2;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=x;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
