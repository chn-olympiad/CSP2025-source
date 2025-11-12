#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll stu[1000010];
bool cmp(ll a, ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,mysc; cin >> n >> m;
	for(int i=0;i<n*m;i++) cin >> stu[i];
	mysc = stu[0];
	sort(stu,stu+n*m,cmp);
	ll cnt = 0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(stu[cnt++]==mysc){
					cout << i << " " << j ;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(stu[cnt++]==mysc){
					cout << i << " " << j ;
				}
			}
		}
	}
	return 0;
} 
