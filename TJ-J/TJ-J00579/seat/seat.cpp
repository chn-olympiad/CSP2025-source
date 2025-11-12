#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int grade;
	bool yes;
};
Node a[100000];
bool cmp(Node x,Node y){
	return x.grade>y.grade;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m; 
	for(int i=1;i<=nm;i++){
		cin>>a[i].grade;
	}
	a[1].yes=1;
	sort(a+1,a+nm+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=nm;i++){
		if(a[i].yes==1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}else{
			if(x==1) y++;
			else x--;
		}
	}
	return 0;
}
