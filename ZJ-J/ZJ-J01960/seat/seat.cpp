#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=205;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int a[maxn];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n*m;i++){
		read(a[i]);
	}
	int p=a[1];
	sort(a+1,a+n*m+1);
	int s=lower_bound(a+1,a+n*m+1,p)-a;
	s=n*m+1-s;
	int l=s/n;
	if(s%n==0) printf("%d %d",l,((l&1) ? n : 1));
	else printf("%d %d",l+1,((l&1) ? n+1-s%n : s%n));
	return 0;
}

