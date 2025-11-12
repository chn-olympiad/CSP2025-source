#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
map<int,int> ma;
int a[111];
bool cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("seat.in","r","stdin");
//	freopen("seat.out","w","stdout");
	ios::sync_with_stdio(0); //yes
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		ma[a[i]]=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int ming;
	for(int i=1;i<=n*m;i++){
		if(ma[a[i]]==1)ming=i;
	}
	int res=ming%n,res1=(ming+n-1)/n/*ceil(ming/n)*/;
	int hang;
	if(res1%2==1)hang=n-res-1;
	else hang=res;
	cout<<res1<<" "<<hang;
}//谁教你这么用sort的 
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]; 
//	}
/*
3
3
3
2
1
4
5
6
7
8
9
*/
