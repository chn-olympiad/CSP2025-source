#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
long long n,m;
long long a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m*((i+1)%2);j!=m*(i%2);j+=((i)%2)*2-1){
			if(q.top()==a[1]){
				cout<<i<<" "<<j+(i%2)<<endl;
			}
			q.pop();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}