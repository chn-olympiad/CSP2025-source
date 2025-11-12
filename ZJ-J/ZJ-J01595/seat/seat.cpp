#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;
int to=2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	priority_queue<int>q;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1){
			s=x;
		}
		q.push(x);
	}int x=1,y=1;
	while(!q.empty()){
		//cout<<y<<" "<<x<<" "<<to<<endl;
		if(q.top()==s){
			cout<<y<<" "<<x;
			break;
		}q.pop();
		if(to==1){
			x--;
			if(x<1){
				x++;
				y++;
				to=2;
			}continue;
		}if(to==2){
			x++;
			if(x>m){
				x--;
				y++;
				to=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}