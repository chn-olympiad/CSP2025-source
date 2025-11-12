#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string t1, t2;
map<string, string> mp;
void test(){
	ans=0;
	for(auto i:mp){
		string temp;
		if(t1.find(i.first)){
			temp=t1;
			auto p=t1.find(i.first);
			int j=0;
			int num=i.first.size();
			while(num){
				temp[p]=i.first[j];
				j++;
				num--;
			}
		}
		if(temp==t2) ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1; i<=q; i++){
		cin>>t1>>t2;
		test();
	}
	return 0;
}