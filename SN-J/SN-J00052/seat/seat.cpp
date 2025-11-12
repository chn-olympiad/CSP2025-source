#include<bits/stdc++.h>
using namespace std;
int n,m,num;
priority_queue<int> pq;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		if(i==1) num=a;
		pq.push(a);
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(pq.top()==num){
					cout<<i<<" "<<j;
					return 0;
				}
				pq.pop();
			}
		}
		else{
			for(int j=1;j<=m;j++){
				if(pq.top()==num){
					cout<<i<<" "<<j;
					return 0;
				}
				pq.pop();
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
