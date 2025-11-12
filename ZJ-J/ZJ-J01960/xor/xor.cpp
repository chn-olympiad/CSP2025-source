#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=5e5+5,maxm=3e6+5;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int n,k;
int a[maxn],f[maxn],t[maxm];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	int p=0;
	memset(t,0xc0,sizeof(t));
	t[0]=0;
	for(int i=1;i<=n;i++){
		p^=a[i];
		f[i]=max(f[i-1],t[p^k]+1);
		t[p]=max(t[p],f[i]);
	}
	printf("%d",f[n]);
	return 0;
} 
