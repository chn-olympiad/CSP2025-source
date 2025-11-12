#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[100],s[10][10],r,k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	r=a[0];
	sort(a,a+n*m,greater<ll>());
	bool f=1;
	for(int i=0;i<m;i++){
		if(f){
			for(int j=0;j<n;j++){
				s[j][i]=a[k];k++;
			}
			f=0;
		}else{
			for(int j=n-1;j>=0;j--){
				s[j][i]=a[k];k++;
			}
			f=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==r){
				cout<<j+1<<' '<<i+1;
			}
		}
	}
	return 0;
}
//感谢CCF出了一道水题
//模拟，启动 
