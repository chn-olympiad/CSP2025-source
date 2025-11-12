#include<bits/stdc++.h>
using namespace std;
const int le=110;
int n,m;
int a[le];
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int score=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			pos=i;
			break; 
		} 
	}
	int x=(pos-1)/n+1,y=(pos-1)%n+1;
	cout<<x<<" ";
	if(x%2==1){
		cout<<y;
	}
	else{
		cout<<n-y+1;
	}
	return 0;
} 
