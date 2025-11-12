#include <bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
}ar[100005],z,s[100005];
bool cmp(int x,int y){
	return x>y;
}
int t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int v=1;v<=t;v++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> ar[i].a >> ar[i].b >> ar[i].c;
			z+=a[i].a;
			if(z<ar[i].b){
				z=ar[i].b;
			}
			if(z<ar[i].c){
				z=ar[i].c;
			}
			s[i] += z;
		}
		sort(z+1,z+n+1,cmp);
		for(int j=1;j<=n/2;j++){
			ans += s[j];
		} 
		cout << ans;
	}
	return 0;
} 
