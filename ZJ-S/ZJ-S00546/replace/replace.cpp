#include<bits/stdc++.h>

using namespace std;

pair<string,string> t[100005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace1.in","r",stdin);
//	freopen("ans.out","w",stdout);
	int n,q;
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>t[i].first>>t[i].second;
	}
	
	while(q--){
		string a,b;
		
		cin>>a>>b;
		int sum=0;
		for(int i=1;i<=n;i++){
//			auto wei=a.find(t[i].first);
//			cout<<i<<endl;
//			if(wei==string::npos) continue;
//			cout<<wei<<endl;
			for(int j=0;j+t[i].first.size()-1<a.size();j++){
				int fla=0;
				string y=a;
				for(int k=j;k<j+t[i].first.size();k++){
//					cout<<j<<" "<<k<<" "<<t[i].first[k-j]<<" "<<a[k]<<" "<<" "<<t[i].second[k-j]<<" "<<b[k]<<endl; 
					if(!(t[i].first[k-j]==a[k])){
						fla=1;break;
					}
					y[k]=t[i].second[k-j];
				}
				if(!fla) {
					if(y==b) sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
