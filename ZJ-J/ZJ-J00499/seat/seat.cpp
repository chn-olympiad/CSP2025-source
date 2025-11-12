#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],n,m;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cx;
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			cx=i;break;
		}
	int sb=1;
	for(int j=1;j<=m;j++){
		if(sb==1){
			for(int i=1;i<=n;i++){
				cx--;
				if(cx==0){
					cout<<j<<" "<<i<<"\n";return 0;
				}
			}	
		}
		if(sb==0){
			for(int i=n;i>=1;i--){
				cx--;
				if(cx==0){
					cout<<j<<" "<<i<<"\n";return 0;
				}
			}	
		}
		sb=!sb;
	}
	return 0;
}
