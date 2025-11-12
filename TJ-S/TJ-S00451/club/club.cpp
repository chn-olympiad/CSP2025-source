#include<bits/stdc++.h>
using namespace std;
int a1[100001],a2[100001],a3[100001];
int n1,n2,n3;
int sum,n,x;
int dfs(int i){
	if(i==n){
		if(sum>x){
			x=sum;
			return sum;
		}
	}
	
		if(n1<(n/2)){
			sum+=a1[i];
			n1++;
			dfs(i+1);
			n1--;
			sum-=a1[i];
		}
		if(n2<(n/2)){
			sum+=a2[i];
			n2++;
			dfs(i+1);
			n2--;
			sum-=a2[i];
		}
		if(n3<(n/2)){
			sum+=a3[i];
			n3++;
			dfs(i+1);
			n3--;
			sum-=a3[i];
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		for(int j=0;j<n;j++){
			dfs(j);
		}
		cout<<x<<endl;
		x=0;
	}
	return 0;
}
