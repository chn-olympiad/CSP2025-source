#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,m,a[N][4],max_,maxx_,maxxx_,m1,b,c,d,p[4],sum,pi;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m;
		pi=m/2;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		m1=m;
		while(m1--){
			for(int i=2;i<=m;i++){
				max_=max(a[i][1],max(a[i][2],a[i][3]));
				maxx_=max(a[i-1][1],max(a[i-1][2],a[i-1][3]));
				if(max_>maxx_){
					swap(a[i][1],a[i-1][1]);
					swap(a[i][2],a[i-1][2]);
					swap(a[i][3],a[i-1][3]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			maxxx_=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxxx_&&p[1]<pi||p[2]>=pi&&a[i][1]>=a[i][3]){
				sum+=a[i][1];
				p[1]++;
			}else if(a[i][2]==maxxx_&&p[2]<pi){
				p[2]++;
				sum+=a[i][2];
			}else{
				sum+=a[i][3];
				p[3]++;
			}
		}
		cout<<sum<<endl;
		sum=0;
		p[1]=0;
		p[2]=0;
		p[3]=0;
	}
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
