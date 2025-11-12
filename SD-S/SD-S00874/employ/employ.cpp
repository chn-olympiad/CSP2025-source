#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
string s;
bool check(){
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			swap(c[i],c[j]);
			if(check())ans++;
			swap(c[i],c[j]);
		}
		for(int j=i+1;j<=n;j++){
			swap(c[i],c[j]);
		}
	}

	return 0;
}
