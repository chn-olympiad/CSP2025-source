#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,t,maxn=0,m=1;
ll a[N][5],b[N][5],c[10];
ll dfs(ll num,ll number){
	if(number>n){
		maxn=max(maxn,num);
		return maxn;
	}
	for(int i=1;i<=m;i++){
		if(c[i]>0){
			num+=a[number++][i];
			c[i]--;
			dfs(num,number);
			c[i]++;
			num-=a[--number][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0){
				m=2;
			}if(a[i][3]!=0){
				m=3;
			}
		}
		c[1]=n/2,c[2]=n/2,c[3]=n/2;dfs(0,0);
		cout<<maxn<<endl;
		maxn=0;
	}return 0;
}
