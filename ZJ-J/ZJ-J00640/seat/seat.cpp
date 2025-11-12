#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector <int> s;
int num_r,n,m;

bool cmp(int x,int y){
	return x>y;
}

void get_ans(int z){
	int x=(z-1)/n+1,y=(z-1)%n+1;
	if(x%2==1)
		cout<<x<<' '<<y;
	else
		cout<<x<<' '<<n-y;
}

void solve(){
	cin>>n>>m>>num_r;
	s.push_back(num_r);
	for(int i=2;i<=n*m;i++){
		int x;cin>>x;
		s.push_back(x);
	}
	sort(s.begin(),s.end(),cmp);
	int cnt_r;
	for(int i=0;i<s.size();i++){
		if(s[i]==num_r){
			cnt_r=i+1;
			break;
		}
	}
	get_ans(cnt_r);
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int T=1;
	while(T--)
		solve();

	return 0;
}


