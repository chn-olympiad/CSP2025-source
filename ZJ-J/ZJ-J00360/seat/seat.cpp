#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,x,y,t;
struct node {
	int grade,id;
}a[11000];
bool cmp(node x,node y){
	return x.grade>y.grade;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i].id==1){
			y=i/n+(i%n>0);
			t=(i%n>0?i%n:n);
			if (y%2==1){
				x=t;
			}
				else {
					x=n-t+1;
				}
		}
	}
	cout<<y<<' '<<x;
}
