#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int mx(int a,int b,int c){
	if(a>=max(b,c))return 1;
	if(b>=max(a,c))return 2;
	return 3;
}
int cx(int a,int b,int c){
	if(mx(a,b,c)==1)return a-max(b,c);
	if(mx(a,b,c)==2)return b-max(a,c);
	return c-max(a,b);
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,ans=0;cin>>n;int A=0,B=0,C=0;int sl;bool ful=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=max(a[i][2],a[i][3])){
				A++;
			}
			else if(a[i][2]>=max(a[i][1],a[i][3]))B++;
			else C++;
		}
		if(A*2<=n and B*2<=n and C*2<=n){
			cout<<"!";
			for(int i=1;i<=n;i++){
				ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
			cout<<ans<<"\n";continue;
		}
		if(A*2>n)sl=1;
		else if(B*2>n)sl=2;
		else sl=3;
		A=0;//B=0;C=0;
		priority_queue<int,vector<int>,greater<int>>q;
		for(int i=1;i<=n;i++){
			int k=mx(a[i][1],a[i][2],a[i][3]);
			if(k==sl){
				if(ful){
					if(a[i][k]-q.top()>(-cx(a[i][1],a[i][2],a[i][3])+a[i][k])){
						ans+=(a[i][k]-q.top());
						q.pop();
						q.push(cx(a[i][1],a[i][2],a[i][3]));
					}
					else{
						ans+=(-cx(a[i][1],a[i][2],a[i][3])+a[i][k]);
					}
				}
				else{
					q.push(cx(a[i][1],a[i][2],a[i][3]));
					ans+=a[i][k];
					A++;
					if(A*2>=n)ful=1;
				}
			}
			else ans+=a[i][k];
		}
		cout<<ans<<"\n";
	}
	return 0;
}