#include <bits/stdc++.h>
using namespace std;
void solve(){
	priority_queue<int,vector<int>,greater<int>> q1,q2,q3;
	int n,sum1=0,sum2=0,sum3=0,ans=0,x,y,z;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>  x >>  y >>  z;
		if( x>= y&& x>= z){
			if((sum1+1)>n/2){
				if( x-q1.top()>max( y, z)){
					ans+= x-q1.top();
					q1.pop();
					q1.push( x-max( y, z));
				}else ans+=max( y, z);
			}else{
				sum1++;
				q1.push( x-max( y, z));
				ans+= x;
			}
		}else if( y>= z){
			
			if((sum2+1)>n/2){
				if( y-q2.top()>max( x, z)){
					ans+= y-q2.top();
					q2.pop();
					q2.push( y-max( x, z));
				}else ans+=max( x, z);
			}else{
				sum2++;
				q2.push( y-max( x, z));
				ans+= y;
			}//cout<<sum2 << " " << q2.top() << " "<< ans << '\n';
		}else{
			if((sum3+1)>n/2){
				if( z-q3.top()>max( x, y)){
					ans+= z-q3.top();
					q3.pop();
					q3.push( z-max( x, y));
				}else ans+=max( x, y);
			}else{
				sum3++;
				q3.push( z-max( x, y));
				ans+= z;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}