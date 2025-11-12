#include<bits/stdc++.h>
using namespace std;
bool comp(int x,int y){
	return x > y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	string a;
	cin >> n >> m >> a;
	int r[n+1];
	for(int i=1;i<=n;i++) cin >> r[i];
	sort(r+1,r+n+1,comp);
	for(int i=1;i<=n;i++) ans+=1;
	cout << ans-1;
	return 0; 
}
