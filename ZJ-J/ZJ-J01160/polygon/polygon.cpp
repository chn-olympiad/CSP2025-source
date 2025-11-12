#include <bits/stdc++.h>
using  namespace std;
#define MODN 998244353
#define inte long long
vector<inte> a;
inte m,ans;
bool check(int m,vector<inte>s){
	if(m<3)return 0;
	inte sum=0;
	for(auto i:s){
		sum+=i;
	}
	if(sum>*max_element(s.begin(),s.end()) * 2){
		return 1;
	}
	return 0;
	
}
bool isIn(vector<inte> v,inte t){
	for(auto i:v){
		if(i==t){
			return 1;
		}
	}
	return 0;
}
void mei(vector<inte> v,inte l){
	if(v.size()>=l){
		if(check(v.size(),v)){
			ans++;
		}
		return;
	}
//	for(auto i:v){
//		cerr<<i<<
//		" ";
//	}
//	cerr<<endl;
	for(int i=0;i<m;i++){
		if(!isIn(v,a[i])){
			v.push_back(a[i]);
			mei(v,l);
			v.pop_back();
		}
	}
}
int main(){
    //cerr<<"deb\n";
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;
    
    for(int i=0;i<m;i++){
    	inte x;
    	cin>>x;
    	a.push_back(x);
	}
	// Only 15 scores, f
	if(m<3){
		//cerr<<m;
		cout<<0;
		return 0;
	}
	if(m==3 && check(3,a)){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=m;i++){
		mei({},i);
	}
	cout<<ans%MODN;
	return 0;
}
// aminoas CCCCCCCCC
