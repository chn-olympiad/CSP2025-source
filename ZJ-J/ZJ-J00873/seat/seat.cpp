#include<bits/stdc++.h>
using namespace std;
int n,m,s;
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		q.push(x);
		if(i==1)s=x;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				if(q.top()==s){
					cout<<i<<' '<<j;
					return 0;
				}
				q.pop();
			}
		else 
			for(int j=n;j>0;j--){
				if(q.top()==s){
					cout<<i<<' '<<j;
					return 0;
				}
				q.pop();
			}
	}
	fclose(stdin);fclose(stdout);
}