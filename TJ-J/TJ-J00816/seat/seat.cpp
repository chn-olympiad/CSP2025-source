#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int map[200][101],a,a_x,a_y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){	
		int cj;
		cin>>cj;
		if(i==1) a=cj;
		q.push(cj);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=q.top();
			q.pop();
			if(map[i][j]==a){
				if(i%2!=0){
					a_x=i;
					a_y=j;
				}else{
					a_x=i;
					a_y=m+1-j;
				}
			}
		}
	}
	cout<<a_x<<" "<<a_y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
