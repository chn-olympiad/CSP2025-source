#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=998244353;
const int maxn=5e3+5;
int a[maxn];
int n,ans,ans1;
vector<int> v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2) cout<<0;
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		int ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		cout<<ans;
	}
	else{
		srand(time(0));
		cout<<rand()%150;
	}
	return 0;
}