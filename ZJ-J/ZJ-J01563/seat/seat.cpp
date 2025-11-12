#include<bits/stdc++.h>
using namespace std;
const int N=1e2+7;
int n,m,pos=1;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		for(int j=i;j>1;j--){
			if(a[j]>a[j-1]&&i!=1){
				swap(a[j],a[j-1]);
				if(j==pos+1) pos=j; 
			}
			else break;
		}
	}
	int x=ceil(pos*1.0/n),y;
	if(pos%n!=0) y=pos%n;
	else y=n;
	if(x%2==0) y=n+1-y;
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 97 98

3 4
7 12 2 5 4 1 6 3 9 10 11 8
*/
