#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
bool cmp(int a,int b){
	return a>b;
}
int m[10009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>m[i]>>x>>y;
		}sort(m+1,m+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=m[i];
		}cout<<ans<<endl;
		
} return 0;
}
