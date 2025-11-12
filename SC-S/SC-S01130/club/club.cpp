#include<bits/stdc++.h>
using namespace std;
int a1[10001],a2[10001],a3[10001];
int t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c;
			cin>>e>>d>>f;
			cout<<max(a+d,max(a+f,max(b+e,max(d+f,max(c+e,c+d)))))<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1,a1+n,cmp);
		int cnt=0;
		for(int i=0;i<n/2;i++){
			cnt+=a1[i];
		} 
		cout<<cnt<<endl;
	}
	return 0;
}