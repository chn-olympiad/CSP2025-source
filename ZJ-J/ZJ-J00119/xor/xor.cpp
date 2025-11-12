#include<iostream>
#include<set>
#define lb lower_bound
using namespace std;
const int N=500001;
typedef long long LL;
struct Node{
	LL Val,Idx;
	bool operator <(Node P)const{
		return Val<P.Val;
	}
};
LL A[N],Pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n,k,Cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int i=1;i<=n;i++)
		Pre[i]=Pre[i-1]^A[i];
	set<Node> S;
	for(int i=1;i<=n;i++){
		S.insert({Pre[i-1],i});
		auto It=S.lb({Pre[i]^k,0});
		if(It==S.end())
			continue;
		if((*It).Val!=(Pre[i]^k))
			continue;
		S.clear(),Cnt++;
	}
	cout<<Cnt<<endl;
	return 0;
}
