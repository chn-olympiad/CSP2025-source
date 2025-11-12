#include <bits/stdc++.h>
using namespace std;
struct score{
	int c,top;
}sc[105];
int n,m,s,tp,x,y;
bool cmp(score p,score q){
	return p.c>q.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>sc[i].c;
		sc[i].top=i;
	}
	sort(sc+1,sc+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(sc[i].top==1){
			tp=i;
			break;
		}
	}
	x=tp/n;
	if(x*n==tp){
		cout<<x<<" ";
	}else{
		cout<<x+1<<" ";
		x++;
	}
	y=tp%n;
	if(x%2){
		cout<<y;
	}else{
		cout<<n-y+1;
	}
	return 0;
}
