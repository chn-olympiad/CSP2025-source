#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int h[100005];
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			h[i]=a;
		}
		sort(h+1,h+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=h[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}

