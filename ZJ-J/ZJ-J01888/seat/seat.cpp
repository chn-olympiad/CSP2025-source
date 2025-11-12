#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int t,s;
}a[105];
bool cmp(stu x,stu y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].t=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].t==1){
			cout<<(i+n-1)/n<<" "<<((((i+n-1)/n)%2)==1?(((i-1)%n)+1):(n-((i-1)%n)));
			return 0;
		}
	}
	return 0;
}
//not AFO
//CSP2025 RP++!!!
//ji dao wan sui!!!
//luogu uid:582006 markkkk_NBFLS
//qiu guan zhu
