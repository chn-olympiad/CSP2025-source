//考号:SN-J00425 姓名:强小轩 学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int n,m,a[105],num;
bool cmp(int X,int Y){
	return X>Y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	int x=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>num)x++;
	}
	int lie=(x-1)/n+1;
	int hang=(x-1)%n+1;
	cout<<lie<<' '<<hang<<'\n';
	return 0;
}







































