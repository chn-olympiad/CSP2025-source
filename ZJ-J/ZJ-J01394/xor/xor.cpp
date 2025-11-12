#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct border{
	ll lb, rb;
};
bool cmp(border a, border b){
	if(a.rb==b.rb) return a.lb < b.lb;
	else return a.rb < b.rb;
}
border bl[1000010];
ll qzh[1000010], ori[1000010];
vector<ll> nbr[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ind=0; cin >> n >> k; qzh[0] = 0;
	nbr[0].push_back(0); 
	for(int i=1;i<=n;i++){
		scanf("%lli",&ori[i]);
		qzh[i] = qzh[i-1]^ori[i];
		int fnd = qzh[i]^k;
		if(nbr[fnd].size()!=0){
			bl[ind].lb = nbr[fnd][nbr[fnd].size()-1]+1;
			bl[ind++].rb = i;
		}
		nbr[qzh[i]].push_back(i);
	}
	sort(bl, bl+ind, cmp);
	ll cnt = 0, rn = 0;
	for(int i=0;i<ind;i++){
		if(bl[i].lb>rn) rn = bl[i].rb, cnt++;
	}
	cout << cnt;
	return 0;
} 
