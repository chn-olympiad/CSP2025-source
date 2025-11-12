#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s=0,r=1,t,c;
bool cmp(int q,int w){
	return q>w;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    c=n;
    for(int i=1;i<=s;i++)
    cin>>a[i];
    int e=a[1];
    sort(a+1,a+1+s,cmp);
for(int i=1;i<=s;i++)
	if(a[i]==e)
	t=i;
	if(t%c!=0){
     r=t/c+t%c;
   if(r%2==0)
   cout<<r<<" "<<c;
   else
   cout<<r<<" "<<t%c;
}
else{
 r=t/c;
   cout<<r<<" "<<c;
}
	return 0;
}