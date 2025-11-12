#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,q,beg,en;
string s[200005][5],s1_,s2_,quest_1,quest_2,awsl;
vector<vector<ll> >nxt;
map<ll,map<ll,ll> > trans;
ll Hash_notreal(string applerrr,ll st,ll en){
	ll hashsum1=0,hashsum2=0;
	for(int i=st;i<en;i++){
		hashsum1=(hashsum1*26+applerrr[i]-'a')%13150327;
		hashsum2=(hashsum2*26+applerrr[i]-'a')%11050111; 
	}
	return hashsum1*hashsum2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1_>>s2_;
		beg=0;
		en=s1_.length();
		for(int j=0;j<s1_.length();j++){
			if(s1_[j]==s2_[j]){
				beg++;
			}else{
				break;
			}
		}
		for(int j=s1_.length()-1;j>=0;j--){
//			if(beg==en)break; 
			if(s1_[j]==s2_[j]){
				en--;
			}else{
				break;
			}
		}
		trans[Hash_notreal(s1_,beg,en)][Hash_notreal(s2_,beg,en)] ++;
	}
	for(int i=0;i<q;i++){
		quest_1=quest_2=awsl;
		cin>>s1_>>s2_;
		if(s1_.length()!=s2_.length()){
			cout<<"0\n";
			continue;
		}
		beg=0;
		en=s1_.length();
		for(int j=0;j<s1_.length();j++){
			if(s1_[j]==s2_[j]){
				beg++;
			}else{
				break;
			}
		}
		for(int j=s1_.length()-1;j>=0;j--){
			if(s1_[j]==s2_[j]){
				en--;
			}else{
				break;
			}
		}
		cout<<	trans[Hash_notreal(s1_,beg,en)][Hash_notreal(s2_,beg,en)]<<'\n';
	}
	return 0;
}
//Ó¦¸ÃÊÇhash/kmp
// 
