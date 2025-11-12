#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int k;
int a[500010];
int ans;
int xk[1010][1010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h=0;
		for(int j=i;j<=n;j++){
			h^=a[j];
			xk[i][j]=h;
		}
	}
	int lst=-1;
	for(int j=1;j<=n;j++){
		int maxx=-1;
		for(int i=1;i<=j;i++){
			if(xk[i][j]==k){
				maxx=i;
			}
		}
		if(maxx==-1||maxx<=lst){
			continue;
		}
		ans++;
		cout<<maxx<<" "<<j<<"\n";
		lst=j;
	}
	cout<<ans;
	return 0;
}
