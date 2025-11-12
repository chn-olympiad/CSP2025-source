#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],l[N],h[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int k=0;
	for(int i=1;i<=m;i++){
		
	   for(int j=1;j<=n;j++){
		   l[a[j+k]]=i;
		   if(i%2==1)h[a[k+j]]=j;
		   else h[a[k+j]]=n-j+1;
	   }
	   k+=n;
}
   
    cout<<l[x]<<" "<<h[x];
	return 0;
}

