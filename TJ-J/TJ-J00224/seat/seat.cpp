#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[109];
int cnt[15][15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int w=a[0];
	int sum=0;
	sort(a,a+(n*m),cmp);
	int q=0;
	for(int i=0;i<m;i++){
		if(q%2==0){
			for(int j=0;j<n;j++){
				cnt[j][i]=a[sum];
				sum++;
			}
			q++;
		}else{
			for(int j=n-1;j>=0;j--){
				cnt[j][i]=a[sum];
				sum++;
			}
			q++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cnt[i][j]==w){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
