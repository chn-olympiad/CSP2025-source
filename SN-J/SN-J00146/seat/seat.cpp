#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,m,id,sum;
vector<int> a;

signed main(){
	FI("seat");
	FO("seat");
	cin>>n>>m;
	for(int i=0,x;i<n*m;i++){
		cin>>x;
		if(i==0) sum=x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),greater<int>());
	id=find(a.begin(),a.end(),sum)-a.begin();
	int l=id/n+1,h;//ап
	int tmp=id%n;
	if(l%2==0){
		h=n-tmp;
	}else{
		h=1+tmp;
	}
	printf("%lld %lld",l,h);
	return 0;
}
