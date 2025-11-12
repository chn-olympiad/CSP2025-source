#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s,t;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			t=i;
			break;
		}
	}
	int x=t/n;
	if(t%n!=0)x++;
	if(x%2==1){
		if(t%n==0){
			cout<<x<<" "<<n;
			return 0;
		}
		else{
			cout<<x<<" "<<t%n;
			return 0;
		}
	}
	else{
		if(t%n==1){
			cout<<x<<" "<<n;
			return 0;
		}
		else{
			cout<<x<<" "<<(n-(t%n)+1)%n;
			return 0;
		}
	}
	return 0;
}
