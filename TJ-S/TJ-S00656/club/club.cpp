#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int sum[4];
struct node{
	int one,oneid,two,twoid,cnt;
}a[maxn];
bool cmp2(node x,node y){
	return x.cnt>y.cnt;
}

struct st{
	int num,id;
}op[4];
bool cmp1(st x,st y){
	return x.num>y.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			sum[i]=n/2;
		}
		for(int i=1;i<=n;i++){
			cin>>op[1].num>>op[2].num>>op[3].num;
			op[1].id=1;
			op[2].id=2;
			op[3].id=3;
			sort(op+1,op+4,cmp1);
//			cout<<op[1].num<<" "<<op[2].num<<" "<<op[3].num;
//			cout<<endl;
			a[i].one=op[1].num;
			a[i].oneid=op[1].id;
			a[i].two=op[2].num;
			a[i].twoid=op[2].id;
			a[i].cnt=a[i].one-a[i].two;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(sum[a[i].oneid]!=0){
				ans+=a[i].one;
				sum[a[i].oneid]--;
			}else{
				ans+=a[i].two;
				sum[a[i].twoid]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
