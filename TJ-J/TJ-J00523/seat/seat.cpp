#include<bits/stdc++.h>
using namespace std;
bool cmp(int p,int q){
	return p>q;
}
int s[66][66],a[666],n,m,A,f_1[5]={0,1,-1,0,0},f_2[5]={0,0,0,1,-1}; 
void ss(int h,int z,int k,int c){
	if(k==A){
		cout<<z<<" "<<h;
		exit(0);
	}
	s[h][z]=k;
	int fx,fy;
	for(int i=1;i<=4;i++){
		fx=h+f_1[i];
		fy=z+f_2[i];
		if(s[fx][fy]==0&&fx<=n&&fy<=m&&fx>0&&fy>0){
			ss(fx,fy,k-1,c+1);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	A=a[0];
	ss(1,1,100,0);
	return 0;
} 
/*
10 10
66 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
