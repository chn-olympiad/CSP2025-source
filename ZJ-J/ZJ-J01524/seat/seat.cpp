#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int score,num;
}a[105];
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int lie,hang,wei;
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			wei=i;
			break;
		}
	}
	if(wei%n==0){
		lie=wei/n;
		if(lie%2==0){
			hang = 1;
		}
		else hang = n;
	}
	else{
		lie = wei/n+1;
		if(lie%2==0){
			hang = n-(wei-(lie-1)*n)+1;
		}
		else hang = wei-(lie-1)*n;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

