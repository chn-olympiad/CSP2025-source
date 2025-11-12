#include <bits/stdc++.h>
using namespace std;
long long T,n,j[4][100005],maxv,z,p[20005],nab;
void abc(long long nw,long long ans,long long a,long long b,long long c){
if(nw>n){
maxv=max(ans,maxv);
return;
}
if(a+1<=z&&j[1][nw]!=0){
abc(nw+1,ans+j[1][nw],a+1,b,c);
}
if(b+1<=z&&j[2][nw]!=0){
abc(nw+1,ans+j[2][nw],a,b+1,c);
}
if(c+1<=z&&j[3][nw]!=0){
abc(nw+1,ans+j[3][nw],a,b,c+1);
}
return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>T;
for(;T>0;T--){
cin>>n;

if(n>=100000){
z=n/2;
nab=0;
for(long long i=1;i<=n;i++){
cin>>j[1][i]>>j[2][i]>>j[3][i];
p[j[1][i]]++;
}
for(long long i=20003;1;i--){
if(nab>=z){
break;
}
if(p[i]>0){
maxv+=i;
p[i]--;
i++;
nab++;
}
}
cout<<maxv<<"\n";
}else{
for(long long i=1;i<=n;i++){
cin>>j[1][i]>>j[2][i]>>j[3][i];
}
z=n/2;
maxv=-1;
abc(1,0,0,0,0);
cout<<maxv<<"\n";
}
}
	return 0;
}
