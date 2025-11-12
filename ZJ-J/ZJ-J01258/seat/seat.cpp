#include<bits/stdc++.h>
using namespace std;
struct student{
	int g,num;
}s[110];
bool cmp(student a,student b){
	return a.g>b.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].g;
		s[i].num=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].num==1){
			if((((i-1)/n)+1)%2==1)	cout<<((i-1)/n+1)<<' '<<(i-1)%n+1;
			else	cout<<((i-1)/n+1)<<' '<<n-(i-1)%n;
		}
	}
	return 0;
}
