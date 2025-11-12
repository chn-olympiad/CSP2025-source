#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
	int num,x;
}d1[maxn],d2[maxn],d3[maxn];
int T;
int n;
int s;
int la,lb,lc;
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		s = 0;
		la = 0;
		lb = 0;
		lc = 0;
		for(int i = 1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			if(x>=y && x>=z){
				la++;
				d1[la].num = i;
				s+=x;
				if(y>=z)
					d1[la].x = x-y;
				else d1[la].x = x-z;
			}
			else if(y>=x && y>=z){
				lb++;
				d2[lb].num = i;
				s+=y;
				if(x>=z)
					d2[lb].x = y-x;
				else d2[lb].x = y-z;
			}
			else if(z>=x && z>=y){
				lc++;
				d3[lc].num = i;
				s+=z;
				if(x>=y)
					d3[lc].x = z-x;
				else d3[lc].x = z-y;
			}
		}
		sort(d1+1,d1+la+1,cmp);
		sort(d2+1,d2+lb+1,cmp);
		sort(d3+1,d3+lc+1,cmp);
		while(la*2>n){
			s-=d1[la].x;
			la--;
		}
		while(lb*2>n){
			s-=d2[lb].x;
			lb--;
		}
		while(lc*2>n){
			s-=d3[lc].x;
			lc--;
		}
		cout<<s<<endl;
	}
	return 0;
}