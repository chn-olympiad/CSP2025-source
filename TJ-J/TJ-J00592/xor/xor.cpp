#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N],b[N];
int ans;

struct Node{
	int x, y;
	bool friend operator< (Node x,Node y){
		if(x.y!=y.y) return x.y>y.y;
		return x.x < y.x;
	}
};
priority_queue<Node> q;


int main() {
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				Node tmp;
				tmp.x=i,tmp.y=j;
				q.push(tmp);
				break;
			}
		}
	}
	int r=0;
	while(!q.empty()){
		Node x=q.top();
		q.pop();
		if(x.x>r){
			ans++;
			r=x.y;
		}
	}
	cout << ans;
	return 0;
}
