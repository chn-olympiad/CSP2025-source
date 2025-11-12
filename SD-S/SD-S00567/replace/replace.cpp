#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1005;
int n,q;
string s1[N],s2[N];
string q1[N],q2[N];
vector<string> change(string s){
	vector<string> v;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=(int)s.size()-(int)s1[i].size();j++){
			string temp=s.substr(j,s1[i].size());
			if(temp==s1[i]){
				//cout<<s.substr(0,j)<<" + "<< s2[i]<<" + "<<s.substr(j+s1[i].size(),(int)s.size()-(j+s1[i].size()-1)+1)<<endl;
				string newS=s.substr(0,j)+s2[i]+s.substr(j+s1[i].size(),(int)s.size()-(j+s1[i].size()-1)+1)  ;
				v.push_back(newS); 
				//cout<<newS<<endl;
			}
		}
	}
	
	return v;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int res=0;
		cin>>q1[i]>>q2[i];
	//	for(int j=1;j<=n;j++){
			vector<string> v=change(q1[i]);
			for(auto u:v){
				if(u==q2[i]){
					res++;
				}
			}
		//}
		cout<<res<<endl;
	}
	
	return 0;
}

