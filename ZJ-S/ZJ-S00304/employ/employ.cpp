#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,m;
long long a[505],h[505],b[505],c[505],t=1;
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  long long i,j;
  char s;
  cin>>n>>m;
  for(i=1;i<=n;i++){
  	cin>>s;
  	s-='0';
  	a[i]=s;
  	h[i]=h[i-1]+1-a[i];
  }
  
  for(i=1;i<=n;i++){
  	cin>>c[i];
  	b[c[i]]++;
  }
  sort(c+1,c+n+1);
  for(i=n;i>=0;i--){
  	b[i]+=b[i+1];
  }
  if(h[n]==0){
  	//cout<<b[1];
  	for(i=1;i<=m;i++){
  	  t=(t*(b[1]-i+1))%M;	
	}
	for(i=1;i<=n-m;i++){
	  t=(t*(n-m-i+1))%M;
	}
	cout<<t;
	return 0;
  }
  /*for(i=1;i<=n;i++)
    cout<<a[i]<<' ';
  cout<<'\n';
  for(i=1;i<=n;i++)
    cout<<b[i]<<' ';
  cout<<'\n';
  for(i=1;i<=n;i++)
    cout<<c[i]<<' ';
  cout<<'\n';
  for(i=1;i<=n;i++)
    cout<<h[i]<<' ';
  cout<<'\n';*/
  for(i=1;i<=n;i++){
  	t=(t*b[h[i]+1])%M;
  }
  cout<<t;
  return 0;
}/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3*/
