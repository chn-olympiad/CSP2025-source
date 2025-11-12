#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],sum;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int v=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			sum=i;
			break;
		}
	}
	v=ceil(1.0*sum/n);
	if(v%2==1) cout<<v<<" "<<sum-(v-1)*n;
	else cout<<v<<" "<<v*n-sum+1;
	return 0;
}
