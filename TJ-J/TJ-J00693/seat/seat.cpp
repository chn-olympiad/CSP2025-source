#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N n*m
int n,m,a[10000],l,b[100][100],i_i=0,j_j=0;
bool jia=false;
bool aaa(int x,int y){
	return x>y;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<N;i++){
		cin>>a[i];
	} 
	l=a[0];
	sort(a,a+N,aaa);
	for(int i=0;i<N;i++){
		if(i_i>=m){
			i_i--;
			j_j++;
			jia=true;
		}else if(i_i<0){
			i_i++;
			j_j++;
			jia=false;
		}
		b[i_i][j_j]=a[i];
		if(a[i]==l){
			cout<<++j_j<<' '<<++i_i;
			return 0;
		}
		if(jia==false){
			i_i++;
		}if(jia==true){
			i_i--;
		}
		
	}
	return 0;
}
