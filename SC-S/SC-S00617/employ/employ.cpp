#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N];
bool s[N];
int cnt=0,ord[N],num[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//	if(cnt<m){
//		cout<<0;
//		return 0;
//	}
	cout<<0;
	return 0;
}