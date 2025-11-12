#include<bits/stdc++.h>
using namespace std;
int n,m,i,r,t,w,cnt,fl,a[200];
bool cmp(int t,int w){return t>w;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	t=w=1;cnt=1;fl=0;
	while(cnt<=n*m){
		if(a[cnt]==r)return cout<<t<<" "<<w,0;
		if(!fl){
			w++;
			if(w>n)t++,w=n,fl=1;
		}
		else if(fl){
			w--;
			if(w<1)t++,w=1,fl=0;
		}
		cnt++;
	}
	return 0;
}