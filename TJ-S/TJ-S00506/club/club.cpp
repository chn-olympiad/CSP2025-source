#include <bits/stdc++.h>
using namespace std;
int t,n;
int falg[200005];
int a[200005],b[200005],c[200005];
int cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		cnt+=a[1]+b[1]+c[1];
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
