#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt1,k=1;
bool cnt[105];
int seat[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt[a[i]]=1;
	}
	int score=a[1];
	for (int i=100;i>=score;i--){
		cnt1+=cnt[i];
	}
	for (int i=1;i<=100;i++){
		for (int j=1;j<=n;j++){
			seat[k++]=j;
		}
		for (int j=n;j>=1;j--){
			seat[k++]=j;
		}
	}
	int c=cnt1/n;
	if (cnt1%n!=0) c++;
	int r=seat[cnt1];
	cout<<c<<' '<<r;
}
