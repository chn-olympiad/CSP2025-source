#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int cnt;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	cout<<(cnt+m-1)/m<<" ";
	if((cnt+m-1)/m%2==1){
		cout<<(cnt-1)%m+1;
	}else{
		cout<<n-(cnt)%m+1;
	}
	return 0;
}
