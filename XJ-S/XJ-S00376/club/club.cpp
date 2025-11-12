#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mid (l+r)/2
const int N=1e5+10;
int n,k,ss;
int a[5][N],bu[5];
int g(int x){
	return x>=k;
}
int gg(int p,int b,int s){
	if(g(bu[b]))return s-a[b][p-1];
	if(p>n)return s;
	bu[b]++;
	int k=0;
    for(int i=1;i<=3;i++){
    	k=max(k,gg(p+1,i,s+a[b][p]));
	}	
	bu[b]--;
	return k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
ss=0;
	cin>>n;
	k=n/2;
	for(int i=1;i<=n;i++){
	  cin>>a[1][i]>>a[2][i]>>a[3][i];
	}
	ss=max(gg(1,1,0),max(gg(1,2,0),gg(1,3,0)));
	cout<<ss<<endl;
}
 } 
