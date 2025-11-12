#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
ll n,m,a[maxn][maxn]={},b[maxn*maxn];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
			cin>>b[i];
		}
		
	
	int k = 1;
	int dfg = b[1];
	sort(b+1,b+n+1,cmp);
	for(int i = 1;i<=n;i++){
	for(int j = 1;j<=m;j++)	{\
			while(k<=n*m){
				a[j][i]  = b[k];
				k++;
				break; 
			}
		
		}
		
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout <<a[i][j]<<" ";
			if(a[i][j]==dfg){
				cout <<j<<" "<<i;
				return 0;	
			}
		}
		cout <<endl;
	}
	return 0;
}
