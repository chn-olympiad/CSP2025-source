#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],s;
struct node{
	int st,en;
}b[1000005];
bool cmp(node x,node y){
	if(x.en!=y.en) return x.en<y.en;
	return x.st<y.st;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	int l=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((a[i-1]^a[j])==k){
				b[++l].st=i;
				b[l].en=j;
				break;
			}
	sort(b+1,b+l+1,cmp);
	int sta=0;
	for(int i=1;i<=l;i++){
		if(b[i].st>sta){
			s++;
			sta=b[i].en;
		}
	}
	cout<<s;
	return 0;
}
