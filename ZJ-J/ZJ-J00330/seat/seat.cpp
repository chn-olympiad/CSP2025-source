#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct node{
	long long f;
	bool s;
};
long long n,m,x;
vector<node> a={{0,0}};
bool emp(node i,node j){
	return i.f>j.f;
}
void print(int x){
	if(x%n==0){
		printf("%lld %lld",x/n,n);
	}else{
		if((x/n+1)%2==1){
			printf("%lld %lld",x/n+1,x%n);
		}else{
			printf("%lld %lld",x/n+1,n-x%n+1);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",&x);
			if(i==1&&j==1){
				a.push_back({x,1});
			}else{
				a.push_back({x,0});
			}
		}
	}
	sort(a.begin()+1,a.end(),emp);
	for(int i=1;i<a.size();i++){
		if(a[i].s==1){
			print(i);
		}
	}
	return 0;
}