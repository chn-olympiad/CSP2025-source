#include <bits/stdc++.h>
using namespace std;
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn=1e1+5;
int score[maxn*maxn],n,m;
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fr1(i,1,n*m)cin>>score[i];
	int p=score[1];
	sort(score+1,score+n*m+1,cmp);
	fr1(i,1,n*m)if(p==score[i])p=i;
	fr1(i,1,m){
		fr1(j,1,n){
			if(p--==1)cout<<i<<" "<<j<<endl;
		}
		i++;
		fr2(j,n,1){
			if(p--==1)cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
