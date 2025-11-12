#include<bits/stdc++.h>
using namespace std;
long long n,k;
queue< pair<string,string> >q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		string s,p;
		cin>>s>>p;
		q.push({s,p});
	}
	for(int i=1;i<=k;i++){
		string s,p;
		cin>>s>>p;
		long long step=q.size(),cnt=0;
		while(step--){
			pair<string,string>f=q.front();
			q.push(q.front());
			q.pop();
			if(f.first.length()<=s.length()){
				long long temp=s.find(f.first);
				if(0<=temp&&temp<s.length()){
					string x=s;
					for(int i=0;f.second[i];i++){
						x[temp+i]=f.second[i];
					}
					if(x.find(p)==0&&p.length()==x.length())cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}