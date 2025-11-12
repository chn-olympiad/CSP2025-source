#include<bits/stdc++.h>
#define int long long
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
int n,q;
string Chan[200009][3];
int Hash[200009][3];
struct question{
	string s_front,s1,s2,s_back;
}d[200009];
string s_front,s1,s2,s_back;
map<int,int> htable,htable2;
const int mod=998244353;
int make_hash(string s){
	int nowhash=0,val=1;
	for(int i=0;i<s.length();i++){
		nowhash=nowhash*271+(s[i]-'a'+1);
		nowhash%=mod;
	}
	return nowhash;
}
bool have[200009];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>Chan[i][1]>>Chan[i][2];
		Hash[i][1]=make_hash(Chan[i][1]);
		Hash[i][2]=make_hash(Chan[i][2]);
		//cout<<"Hash:"<<Hash[i][1]<<" "<<Hash[i][2]<<"\n";
	}
	while(q--){
		string s,ss;
		cin>>s>>ss;
		if(s.length()!=ss.length()){
			cout<<"0\n";
			continue;
		}
		int len=s.length();
		s_front="";
		s_back="";
		s1="";
		s2="";
		int first_pos=-1,last_pos=-1;
		for(int i=0;i<len;i++){
			if(s[i]!=ss[i]){
				if(first_pos==-1) first_pos=i;
				last_pos=i;
			}
		}
		for(int i=0;i<first_pos;i++){
			s_front+=s[i];
		}
		for(int i=first_pos;i<=last_pos;i++){
			s1+=s[i];
			s2+=ss[i];
		}
		for(int i=last_pos+1;i<len;i++){
			s_back+=s[i];
		}
	//	cout<<s_front<<" "<<s1<<" "<<s2<<" "<<s_back<<"\n";
		htable.clear();
		htable2.clear();
		string chk_string1=s_front+s1,chk_string2=s_front+s2;
		for(int i=1;i<=n;i++) have[i]=0;
		int nowhash,val=1;
		nowhash=0;
		for(int i=chk_string1.length()-1;i>=0;i--){
			nowhash=nowhash+(chk_string1[i]-'a'+1)*val;
			val*=271;
			nowhash%=mod;
			val%=mod;
			htable[nowhash]=1;
	//		cout<<"add:"<<nowhash<<"\n";
		}
		nowhash=0,val=1;
		for(int i=chk_string2.length()-1;i>=0;i--){
			nowhash=nowhash+(chk_string2[i]-'a'+1)*val;
			val*=271;
			nowhash%=mod;
			val%=mod;
			htable2[nowhash]=1;
	//		cout<<"add:"<<nowhash<<"\n";
		}
		for(int i=1;i<=n;i++){
	//		cout<<":"<<i<<"\n";
			if(htable[Hash[i][1]]&&htable2[Hash[i][2]]){
				have[i]=1;
	//			cout<<"! "<<i<<"\n";
			}
		}
		htable.clear();
		htable2.clear();
		nowhash=0;
		chk_string1=s1+s_back,chk_string2=s2+s_back;
		for(int i=0;i<chk_string1.length();i++){
			nowhash=nowhash*271+(chk_string1[i]-'a'+1);
			nowhash%=mod;
			htable[nowhash]=1;
	//		cout<<"add:"<<nowhash<<"\n";
		}
		nowhash=0;
		for(int i=0;i<chk_string2.length();i++){
			nowhash=nowhash*271+(chk_string2[i]-'a'+1);
			nowhash%=mod;
			htable2[nowhash]=1;
	//		cout<<"add:"<<nowhash<<"\n";
		}
		for(int i=1;i<=n;i++){
	//		cout<<":"<<i<<"\n";
			if(htable[Hash[i][1]]&&htable2[Hash[i][2]]){
				have[i]=1;
	//			cout<<"! "<<i<<"\n";
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=have[i];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 1
abd afe
bdy fey
bdyl feyl
szabdyl szafeyl
*/
