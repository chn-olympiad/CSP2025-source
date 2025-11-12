#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define ll long long
const int MAXN=5e5+5,MAXM=2e6+5;
struct node{
	int l,r;
}v[MAXN];
ll n,k,u=0,nl=0,num,anss=0,a[MAXN],b[MAXN],d[MAXM];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	d[b[0]]=1;
	for(int i=1;i<=n;i++){
		num=k^b[i];
		if(d[num]){
			v[++u]={d[num],i};
		}
		d[b[i]]=i+1;
	}
	for(int i=1;i<=u;i++){
		if(nl<v[i].l){
			anss++;
			nl=v[i].r;
		}
	}
	cout<<anss;
	return 0;
}
