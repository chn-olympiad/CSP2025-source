#include<bits/stdc++.h>
using namespace std;
int point[110],r_point,r_num;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int N=n*m;
	for(int i=0;i<N;i++){
		cin>>point[i];
	}
	r_point=point[0];
	sort(point,point+N);
	for(int i=N-1,j=0;i>=0;i--,j++){
		if(point[i]==r_point){
			r_num=j;
		}
	}
	int i=1,j=1;
	while(r_num--){
		if(j%2!=0&&i==n||j%2==0&&i==1){
			j++;
		}else if(j%2!=0){
			i++;
		}else{
			i--;
		}
	}
	cout<<j<<" "<<i;
	return 0;
}
