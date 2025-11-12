#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int score;
	int num;
};
node a[105];
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	node r=a[1];
	std::sort(a+1,a+1+cnt,cmp);
	int c=-1;
	for(int i=1;i<=cnt;i++){
		if(a[i].num==1){
			c=i-1;
			break;
		}
	}
	cout<<(c/n)+1<<' ';
	if((c/n)%2==0){
		cout<<c%n+1;
	}
	else{
		cout<<n-(c%n);
	}
	return 0;
}

