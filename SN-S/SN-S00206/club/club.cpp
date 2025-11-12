#include<bits/stdc++.h>
using namespace std;
int t;
struct team{
	int f,s,t;
};
int maxa[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		team a[100005];
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			maxa[i]=max(a[i].t,max(a[i].f,a[i].s));
			sum+=maxa[i];
		}
		cout<<sum<<endl;
		
	}
	
	return 0;
}
