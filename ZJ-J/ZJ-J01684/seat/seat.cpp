#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=137;
int n,m,cnt;
struct node{
	int fs,id;
}a[N];
bool cmp(node i,node j){
	return i.fs>j.fs;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].fs,a[i].id=i;
	sort(1+a,1+a+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}