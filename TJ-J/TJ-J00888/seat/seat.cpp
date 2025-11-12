#include <bits/stdc++.h>
using namespace std;
long long score[105];
int n,m;
int jishu = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>score[i];
	}
	int R = score[1];
	sort(score,score+n*m+1);
	int ind;
	for(int i = 1;i<=n*m;i++){
		if(score[i]==R){
			ind = i;
			break;
		}
	}
	int x = 0;
	int y = 1;
	for(int i = 1;i<=ind;i++){
		if(x+1<=n){
			x++;
		}
		else{
			y++;
			x = 1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
