#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
double a[110];
bool cmp(double x,double y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	double score=a[1];
	sort(a+1,a+1+num,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			cnt++;
			if(i%2==0) k=n-j+1;
			else k=j;
			if(a[cnt]==score){
				cout<<i<<" "<<k;
				break;
			}
		}
	}
	return 0;
}