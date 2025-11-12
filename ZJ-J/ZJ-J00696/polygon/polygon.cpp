#include<bits/stdc++.h>
using namespace std;
long long int ans=0;
void fzks(vector<int> v,int sum,int num,int w,int m){
	w=max(w,v[num]);
	sum+=v[num];
	if(m>=3){
		if(sum>2*w){
			ans++;
			if(sum>2*w+v[0]) ans++;
		}
	}
	for(int i=num+1;i<v.size();i++){
		fzks(v,sum,i,w,m+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	vector<int> v;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	fzks(v,0,0,v[0],1);
	cout<<ans%998244353;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
