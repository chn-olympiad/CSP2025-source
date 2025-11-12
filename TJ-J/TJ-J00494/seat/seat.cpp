#include<iostream>
#include<algorithm>
using namespace std;
int a[110],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){ cin>>a[i];}
	int g=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(p=1;p<=n*m;p++){
		if(g==a[p]){ break;}
	}
//	cout<<p<<endl;
	int c=(p+n-1)/n,r;//c:ÁÐ r:ÐÐ 
	if(c%2){ r=p-(c-1)*n;}
	else{ r=n-p%n;}
	cout<<c<<' '<<r;
	return 0;
}
//1:2 2 99 100 97 98
//2:2 2 98 100 97 99
