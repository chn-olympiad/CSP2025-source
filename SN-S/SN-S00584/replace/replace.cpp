#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const ll N=2e5+10;
const ull bs=1145141;
using namespace std;
template<typename Tpp>
Tpp pw(Tpp b,ll e){
	Tpp ret=1;
	while(e){
		if(e&1){
			ret*=b;
		}
		b=b*b;
		e>>=1;
	}
	return ret;
}
struct sr{
	int size;
	vector<char> s;
	vector<ull>hash;
	void in(){
		hash.clear();s.clear();
		hash.resize(0);s.resize(0);
		s.push_back('a');hash.push_back(0);
		string tp;cin>>tp;size=tp.size();
		for(int i=1;i<=size;i++){
			s.push_back(tp[i-1]);
			hash.push_back(hash[i-1]*bs+s[i]);
		}
		return ;
	}
	ull hs(int l,int r){
		return hash[r]-hash[l-1]*pw(bs,r-l+1);
	}
	ull hs(){
		return hs(1,size);
	}
}a[N],b[N],s1,s2;
int n,q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		a[i].in();b[i].in();
		cout<<a[i].hs()<<' '<<b[i].hs()<<endl;
	}
	while(q--){
		int ans=0;
		s1.in();s2.in();
		for(int i=1;i<=s1.size;i++){
			for(int j=1;j<=n;j++){
				if(s1.hs(i,i+a[j].size-1)==a[j].hs()){
					if(s2.hs(i,i+b[j].size-1)==b[j].hs()){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

