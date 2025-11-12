#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1145],ax,ay,sx;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++)cin>>a[i];
	int r=a[1];
	sort(a,a+s+1);
	int k=0;
	for(int i=s;i>=1;i--){
		k++;
        if(a[i]==r)sx=k;
	}
	if(((sx-1)/n+1)%2==1){
		ax=(sx-1)%n+1;
	}else{
		if(((sx-1)/n+1)%2==0){
		    ax=n-((sx-1)%n);
		}
	}
	ay=(sx-1)/n+1;
	cout<<ay<<" "<<ax;
	return 0;
} 
