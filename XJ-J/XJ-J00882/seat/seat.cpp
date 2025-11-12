#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int l_a=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]==l_a){
			l_a=i;
		}
	}
	int x=l_a/m;
	if(l_a%n==0){
		if(x%2==1){
			cout<<x<<" "<<m;
		}
		else cout<<x<<" "<<1;
	}
	else{
		int x=l_a/m+1;
		if(x%2==1){
			cout<<x<<" "<<l_a-(x-1)*m;
		}
		else cout<<x<<" "<<x*m-l_a+1;
	}
	return 0;
}
