//SN-J01073 郭逸凡 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int cseat[115];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	cin>>r;
	cseat[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>cseat[i];
	}
	sort(cseat+1,cseat+n*m+1,cmp);
	queue<int> q;
	for(int i=1;i<=n*m;i++){
		q.push(cseat[i]);
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(q.front()==r){
					cout<<i<<" "<<j;
					return 0;
				}else{
					q.pop();
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(q.front()==r){
					cout<<j<<" "<<i;
					return 0;
				}else{
					q.pop();
				}
			}
		}
	}
	return 0;
} 
