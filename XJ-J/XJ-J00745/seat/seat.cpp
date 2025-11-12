#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=1e6+16;
int s[MAXN];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int rc=s[1],idx;
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==rc){
			idx=i;
			break;
		}
	}
	int r;
	if(idx<n)r=1;
	else if(idx%n!=0)r=idx/n+1; 
	else r=idx/n;
	if(r%2)cout<<r<<" "<<idx-(r-1)*n;
	else cout<<r<<" "<<n-(idx-(r-1)*n)+1;
	return 0;
}
