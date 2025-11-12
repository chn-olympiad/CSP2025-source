//hhz RP++ SCORE++ pts++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m;
struct node{
	int a,id;
}t[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++){
		cin>>t[i].a;
		t[i].id=i;
	}
	sort(t+1,t+h+1,cmp);
	for(int i=1;i<=h;i++){
		if(t[i].id==1){
			if(i<=n){
				cout<<1<<" "<<i;
			}
			else{
				if(i/n%2==1||(!(i%n==0)&&(i/n%2))){
					cout<<i/n+1<<" "<<(n-i%n+1);
				}
				else{
					cout<<i/n+1<<" "<<(i%n);
				}
			}
		}
	}
	return 0;
}
