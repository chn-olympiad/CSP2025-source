#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std; 


const int N = 1e5+5;

struct node{
	int x,y,z;
}lis[N];
struct member{
	int id,w;
	bool operator<(const member&x)const{
		return w>x.w;
	}
};
int n;
priority_queue<member>X,Y,Z;
int numx,numy,numz;
int ans;

void solve(){
	cin >> n;
	For(i, 1, n){
		cin >> lis[i].x >> lis[i].y >> lis[i].z;
	}
	while(X.size())X.pop();
	while(Y.size())Y.pop();
	while(Z.size())Z.pop();
	numx=0;numy=0;numz=0;
	ans = 0;
	For(i, 1, n){
		int x = lis[i].x,y = lis[i].y,z = lis[i].z;
		if(x>=y&&x>=z){
			X.push({i,min(x-y,x-z)});
			numx++;
			ans += x;
		}else if(y>=x&&y>=z){
			Y.push({i,min(y-x,y-z)});
			numy++;
			ans += y;
		}else{
			Z.push({i,min(z-x,z-y)});
			numz++;
			ans += z;
		}
	}
	int p = n/2;
	if(numx>p){
		while(numx>p){
			member t = X.top();
			X.pop();
			numx--;
			ans -= t.w;
			
		}
	}else if(numy>p){
		while(numy>p){
			member t = Y.top();
			Y.pop();
			numy--;
			ans -= t.w;
			//cout << t.id << " " << t.w << "\n";
		}
	}else if(numz>p){
		while(numz>p){
			member t = Z.top();
			Z.pop();
			numz--;
			ans -= t.w;
		}
	}
	cout << ans << "\n";
}

int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

