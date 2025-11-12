#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define ll long long
int Pair,question;
map<string,string> Match;
map<int,int> B_match;
pair<string,string> cnt[200005];
string qu[200005];
bool check(string a,string b,int i){
	int ttttttt=a.find(cnt[i].first),tttttt=b.find(cnt[i].second);
	if(ttttttt==-1 || tttttt==-1) return false;
	int t=ttttttt+cnt[i].first.size();
	for(int j=0;j<ttttttt;j++) if(a[j]!=b[j]) return false;
	for(int k=t;k<a.size();k++) if(a[k]!=b[k]) return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>Pair>>question;
	if(Pair<=1000 && question<=1000){
		for(int i=1;i<=Pair;i++)
			cin>>cnt[i].first>>cnt[i].second;
		while(question--){
			string qua,qub;
			cin>>qua>>qub;
			if(qua.size()!=qub.size()) cout<<0<<endl;
			else{
				int ans=0;
				for(int i=1;i<=Pair;i++){
					if(qua.find(cnt[i].first)==qub.find(cnt[i].second) && check(qua,qub,i)) ans++;
				}
				cout<<ans<<endl;
			}
		}
	}
	else{
		for(int i=1;i<=Pair;i++){
			string a,b;
			cin>>a>>b;
			int aa=a.find("b");
			int bb=b.find("b");
			B_match[aa-bb]++;
		}
		while(question--){
			string a,b;
			cin>>a>>b;
			if(a.size()!=b.size()) cout<<0<<endl;
			else{
				int aa=a.find("b");
				int bb=b.find("b");
				cout<<B_match[aa-bb]<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
