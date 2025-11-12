#include<iostream>
using namespace std;
int p[3],a[100010][3],s;
void dfs(int n,int i,int x){
	if(i == n){
		s = max(s,x);
		return;
	}
	for(int j = 0;j < 3;j++)
		if(p[j] < n / 2){
			p[j]++;
			dfs(n,i + 1,x + a[i][j]); 
			p[j]--;
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i < n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		s = 0;
		dfs(n,0,0);
		cout<<s<<endl;
	}
	return 0;
}