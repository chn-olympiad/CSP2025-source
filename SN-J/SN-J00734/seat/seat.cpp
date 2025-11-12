#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	int x;
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	x=a[0];//Ð¡R³É¼¨ 
	sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int t1=x/n+1;
	int t2=x%n;
	cout<<t1<<" ";
	if(t1%2==0){
		cout<<n-t2<<endl;
	}
	else cout<<t2+1<<endl;
	return 0;
}

