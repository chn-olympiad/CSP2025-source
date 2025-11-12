#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
long long n,m,k;
struct node {
	long long fs;
	long long id;
	long long x,y;
} a[155];
bool cmp(node i,node j){
	return i.fs>j.fs||i.fs==j.fs&&i.id<j.id;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				a[k].x=j;
				a[k].y=i;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
				a[k].x=j;
				a[k].y=i;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<a[i].y<<" "<<a[i].x;
			return 0;
		}
	}
	return 0;
}