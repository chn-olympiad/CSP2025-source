#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 1e8;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<pair<string,string>> a(n);
	int min_s=INF;
	for(int i=0;i<n;++i){
		cin>>a[i].first>>a[i].second;
		int t=a[i].first.size();
		min_s=min(t,min_s);
	}
	for(int i=0;i<q;++i){
		int res=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<=s1.size();++j){
			for(int k=min_s;k<=s1.size()-j;++k){
				string t = s1.substr(j,k);
				for(int l=0;l<n;++l){
					if(t == a[l].first){
						t=a[l].second;
					}
				}
				if(s1.substr(0,j)+t+s1.substr(j+k,s1.size()-j+k)==s2){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}