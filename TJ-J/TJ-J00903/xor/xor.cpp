#include <bits/stdc++.h>
using namespace std;
vector<int> l;
vector<int> r;
bool check(int a,int b){
	for(int i=0;i<l.size();i++){
		if(!(a>r[i]||b<l[i])) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> s(n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)==false) continue;
			if((s[j]^s[i-1])==k){
				l.push_back(i);
				r.push_back(j);
				ans++;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
