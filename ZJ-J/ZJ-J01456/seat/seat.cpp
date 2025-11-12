#include<bits/stdc++.h>
using namespace std;
struct stu{
	int no;
	int score;
};
stu x[110];
bool g(stu a,stu b){
	if(a.score>b.score)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,r;
	cin>>m>>n;
	int sum=m*n;
	for(int i=1;i<=sum;i++){
		x[i].no=i;
		cin>>x[i].score;
	}
	sort(x+1,x+sum+1,g);
	for(int i=1;i<=sum;i++){
		if(x[i].no==1){
			r=i;
			break;
		}
	}
	int x,y;
	x=ceil(r*1.0/m);
	cout<<x<<" ";
	if(x%2==1)y=r-(x-1)*3;
	else y=m-r%m+1;
	if(y>m)y-=m;
	cout<<y;
	return 0;
}
