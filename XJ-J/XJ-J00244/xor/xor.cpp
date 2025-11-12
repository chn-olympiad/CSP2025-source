#include<bits/stdc++.h>
using namespace std;
long long int a[500009],i,j,ans,k,s,n,K,f;
int main()
{
		freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>n>>K;
for(i=1;i<=n;i++){
cin>>a[i];
if(a[i]==1)s++;}
if(K==1&&s==n){
cout<<n;return 0;}
if(K==0&&s==n){
cout<<n/2+n%2;return 0;}


for(i=1;i<=n;i++){
	f=0;
for(j=i;j<=n;j++)
{
	if(i==j&&a[i]==K)
	{ans++;break;}
	
	s=a[i];
	
	for(k=i+1;k<=j;k++)
	{
	s+= !(s||a[k]);
	if(s==K) 
	{ans++;i=j;f=1;break;}
	}
	
	if(f==1)
	break;
}
    
}

cout<<ans;
}   
//特殊性质  A+B  15--20分 

