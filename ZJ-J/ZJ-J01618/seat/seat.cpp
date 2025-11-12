#include<bits/stdc++.h>
#pragma GCC optimize(2,3,4,5,6,7,"Ofast")
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,a[1145],l,h,p,pos;
bool cmp(int i,int j){return i>j;}
int main(){
   freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(p==a[i]){pos=i;break;}
	l=pos/n+(pos%n!=0);
	if(l%2==1){
		h=pos%n;
		if(h==0)h=n;
	}
	else {
		h=n-pos%n+1;
		if(pos%n==0)h=1;
	}
	cout<<l<<' '<<h;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/

