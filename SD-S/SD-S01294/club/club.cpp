#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+19;
int T,n,a[N],b[N],c[N];
int ans=0;
struct node{
	int mx,mid;
};
node chk(int x,int y,int z){
	node res;
	if(x>=y&&x>=z){
		res.mx=1;
		if(y>=z) res.mid=x-y;
		else res.mid=x-z;
	}else if(y>=z&&y>=x){
		res.mx=2;
		if(x>=z) res.mid=y-x;
		else res.mid=y-z;
	}else{
		res.mx=3;
		if(y>=x) res.mid=z-y;
		else res.mid=z-x; 
	}
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	int c1,c2,c3;
	while(T--){
		ans=0;
		priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
		cin >> n;
		c1=0,c2=0,c3=0;
//		while(!q1.empty()) q1.pop();
//		while(!q2.empty()) q2.pop();
//		while(!q3.empty()) q3.pop();
		for(int i=1;i<=n;++i){
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int i=1;i<=n;++i){
			node tmp=chk(a[i],b[i],c[i]);
			//cout << tmp.mx << ' ' << tmp.mid << '\n';
			if(tmp.mx==1){
				if(c1<(n/2)){
					c1++;
					q1.push(tmp.mid);
					ans+=a[i];
				}else{
					q1.push(tmp.mid);
					ans+=a[i];
					ans-=q1.top();
					q1.pop();
				}
			}else if(tmp.mx==2){
				if(c2<(n/2)){
					c2++;
					q2.push(tmp.mid);
					ans+=b[i];
				}else{
					q2.push(tmp.mid);
					ans+=b[i];
					ans-=q2.top();
					q2.pop();
				}
			}else{
				if(c3<(n/2)){
					c3++;
					q3.push(tmp.mid);
					ans+=c[i];
				}else{
					q3.push(tmp.mid);
					ans+=c[i];
					ans-=q3.top();
					q3.pop();
				}
			}
		}cout << ans << '\n';
	}	
	return 0;
} 
//我常常追忆过去 
