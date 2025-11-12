#include<bits/stdc++.h>
using namespace std;
struct bb{
    int s,id;
}a[105];
int cmp(bb x,bb y){//da -> xiao
	return x.s>y.s;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i].s;
	a[1].id=1;
    sort(a+1,a+1+n*m,cmp);
    int z=0,h=0,l=0;
    for(int i=1;i<=n*m;i++){
    	if(a[i].id==1){
    		z=i;
    		break;
		}
	}
	l=z/n;//列 z/n 
	h=z%n;//行先是z%n再判奇偶 
	if(h>0) l++;
	if(h==0) h=n;
	if(l%2==0)
	  h=n-h+1;
	cout<<l<<' '<<h;
	return 0;
}
