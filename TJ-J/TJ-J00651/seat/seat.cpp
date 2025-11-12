#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    vector<int>a(n*m+1);
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int num=a[1];
    sort(a.begin()+1,a.end());
    reverse(a.begin()+1,a.end());
    int s=0;
    for(int i=1;i<=n*m;i++){
		s++;
		if(a[i]==num)break;
	}int x=s/n,y=s%n;
	if(y)x++;
	if(y==0)y=n;
	if(x%2==0)y=m-y+1;
	cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
