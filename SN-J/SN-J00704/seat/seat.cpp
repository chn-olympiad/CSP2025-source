#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,s,ss,a[N];
bool xxx(){
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	if(n==1 and m==1){
		cout<<"1 1";
		return 0;
	}
	int maxn=0,i=1;
	while(xxx()==1){
		for(;i<=n*m;i++){
			if(a[i]<a[maxn]){
				swap(a[i],a[maxn]);
			}
		}
		if(a[i]==s){
			ss=i;
		}
		i++;
	}
	if(n==1){
		cout<<"1 "<<ss;
		return 0;
	}
	if(m==1){
		cout<<ss<<" 1";
		return 0;
	}
	if(n<=10){
		int c=(ss-1)/n+1,b=(ss-1)%n+1;
		if(c%2==0){
			cout<<c<<' '<<b; 
			return 0;
		}
		if(c%2==1){
			cout<<c<<' '<<n-b;
			return 0;
		}
	}
	return 0;
}
