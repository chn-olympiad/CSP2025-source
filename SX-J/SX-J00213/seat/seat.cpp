#include <bits/stdc++.h>
using namespace std;

int a[105];
int n,m;
int vis;
int num;

bool cmp(int a,int b){
    return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(0);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    vis=a[1];
    sort(a+1,a+1+(n*m) ,cmp);
    for(int i=1;i<=n*m;i++) if(a[i]==vis){num=i;}
    int x=num/n,y=num%n;
//    cout<<num;
    if(x%2==0){
    	if(y==0) cout<<x<<" "<<1;
    	else cout<<(x+1)<<" "<<y;
	}
	else{
		if(y==0) cout<<x<<" "<<n;
		else cout<<(x+1)<<" "<<n-y+1;
	}
	return 0;
}