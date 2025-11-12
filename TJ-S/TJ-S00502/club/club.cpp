#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,sum=0,maxn=0;
struct peo{
	int a;
	int b;
	int c;
}s[500005];
bool cmp1(struct peo x,struct peo y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		if(s[1].b==0 && s[1].c==0)
		{
			sort(s+1,s+n+1,cmp1);
			for(int i=1;i<=k;i++){
				sum+=s[i].a;
			}
					cout<<sum<<endl;
		}
		if(n==2){
			maxn=max(maxn,s[1].a+s[2].b);
			maxn=max(maxn,s[1].a+s[2].c);
			maxn=max(maxn,s[1].b+s[2].a);
			maxn=max(maxn,s[1].b+s[2].c);
			maxn=max(maxn,s[1].c+s[2].a);
			maxn=max(maxn,s[1].c+s[2].b);
			cout<<maxn<<endl;
		}
		t--;
	}
	return 0;
}
