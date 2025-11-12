#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1],grade=-1;//小R的分数、排名 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			grade=i;
			break;
		}
	}
	int c=int(ceil(grade*1.0/n)),r;//小R的列
	int tmp=grade-(c-1)*n;//一列坐满了剩余的
	if(c&1)//奇数列（从上往下） 
		r=tmp;
	else//偶数列（从下往上） 
		r=m-tmp+1;
	cout<<c<<" "<<r;
	return 0;
} 
