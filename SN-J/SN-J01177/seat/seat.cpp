#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,k,c[105];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>c[i];
	x=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	    if(c[i]==x){
	    	k=i;
	    	break;
		}
	y=k/n;
	if(y%2==1) 
	    if(k%n==0) cout<<y<<" "<<n;
	    else cout<<y+1<<" "<<n-(k%n)+1;
	else
	    if(k%n==0) cout<<y<<" "<<1;
	    else cout<<y+1<<" "<<(k%n);
    return 0;
}
