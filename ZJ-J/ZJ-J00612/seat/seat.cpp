#include<bits/stdc++.h>
using namespace std;
long long i,n,m,s;
struct no{
	long long a,b;
}a[110];
bool cmp(no q,no h){
	return q.a>h.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i].a,a[i].b=i;
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i].b==1){
			if(i%n==0){
				cout<<i/n<<" ";
				s=i/n;
				if(s%2==1) cout<<n;
				else cout<<1;
			}
			else{
				cout<<i/n+1<<" ";
				s=i/n+1;
				if(s%2==1) cout<<i%n;
				else cout<<n-i%n+1;
			}
		}
	return 0;
}

