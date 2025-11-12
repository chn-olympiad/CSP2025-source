#include<bits/stdc++.h>
using namespace std;
#define int long long
struct student{
	int id,score;
}a[110];
bool cmp(student x,student y){
	return x.score>y.score;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		a[i].id=i;
		cin>>a[i].score;
	}
	sort(a+1,a+sum+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[k].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
