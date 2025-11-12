#include<bits/stdc++.h>
#define ll long long
const ll maxn=10*10+5;
using namespace std;
ll n,m,cnt=1;
struct ty{
	ll grade;
	ll id;
}a[maxn];
bool cmp(ty a1,ty a2){
	return a1.grade>a2.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;){
		for(int j=1;j<=n;j++,cnt++){
			if(a[cnt].id==1){
				cout<<i<<" "<<j;
			}
		}
		i++;
		for(int j=n;j>=1;j--,cnt++){
			if(a[cnt].id==1){
				cout<<i<<" "<<j;
			}
		}
		i++;
	}
	return 0;
}
/*
          CCF	
          
    \      |      /
     \     |     /
      \    |    /  
       \   |   /
        \  |  /
        -------
       /       \
       \       /
        -------
*/

