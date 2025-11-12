#include<bits/stdc++.h>
#define lon long long
using namespace std;
int n,k;//500010 2^20
int a[500010];
int qz[500010];
int ans;
bool cz[1048600];//1048576
queue<int> q;
int w,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1] xor a[i];
	}cz[0]=1;
	for(int i=1;i<=n;i++){
		if(cz[k xor qz[i] xor qz[w]]){
			ans++;
			while(!q.empty()){
				cz[q.front()]=0;
				q.pop();
			}
			w=i;
		}else{
			s=qz[i] xor qz[w];
			cz[s]=1;
			if(s) q.push(s);
		}
	}
	cout<<ans;
	return 0;
}
