#include<bits/stdc++.h>
using namespace std;
string s[200010][3],t[200010][3];
int n,q;
string s1,s2;
bool flag=true;
pair<int,pair<int,int> > len[500010];
bool cmp(int x,int y){
	if(len[x].second.first==len[y].second.first){
		if(len[x].second.second==len[y].second.second) return x<y;
		return len[x].second.second<len[y].second.second;
	}
	return len[x].second.first<len[y].second.first;
}
int p[500010];
long long tr[5000010];
int lowbit(int x){
	return x&-x;
}
void add(int x,int k){
	for(;x<=5000001;x+=lowbit(x)) tr[x]+=k;
}
int ask(int x){
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=tr[x];
	return ans;
}
vector<int> v[10000010];
long long ans[200010];
map<pair<string,string>,int> M;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		p[i]=i;
		cin>>s[i][1]>>s[i][2];
		int cnt1=0,cnt2=0;
		for(auto j:s[i][1]) cnt1+=(j=='a'),cnt2+=(j=='b');
		flag&=((cnt1+cnt2==s[i][1].length())&&cnt2==1);
		cnt1=cnt2=0;
		for(auto j:s[i][2]) cnt1+=(j=='a'),cnt2+=(j=='b');
		flag&=((cnt1+cnt2==s[i][1].length())&&cnt2==1);
	}
	for(int i=1;i<=q;i++){
		p[i+n]=i+n;
		cin>>t[i][1]>>t[i][2];
		int cnt1=0,cnt2=0;
		for(auto j:t[i][1]) cnt1+=(j=='a'),cnt2+=(j=='b');
		flag&=((cnt1+cnt2==t[i][1].length())&&cnt2==1);
		cnt1=cnt2=0;
		for(auto j:t[i][2]) cnt1+=(j=='a'),cnt2+=(j=='b');
		flag&=((cnt1+cnt2==t[i][1].length())&&cnt2==1);
	}
	if(flag){
		for(int i=1;i<=n;i++){
			int pos1=0,pos2=0;
			for(int j=0;j<s[i][1].length();j++){
				if(s[i][1][j]=='b'){
					pos1=j;
					break;
				}
			}
			for(int j=0;j<s[i][2].length();j++){
				if(s[i][2][j]=='b'){
					pos2=j;
					break;
				}
			}
			len[i].first=pos2-pos1;
			len[i].second={pos1,s[i][1].length()-pos2-1};
			v[pos2-pos1+5000000].emplace_back(i);
		}
		for(int i=1;i<=q;i++){
			int pos1=0,pos2=0;
			for(int j=0;j<t[i][1].length();j++){
				if(t[i][1][j]=='b'){
					pos1=j;
					break;
				}
			}
			for(int j=0;j<t[i][2].length();j++){
				if(t[i][2][j]=='b'){
					pos2=j;
					break;
				}
			}
			len[i+n].first=pos2-pos1;
			len[i+n].second={pos1,t[i][1].length()-pos2-1};
			v[pos2-pos1+5000000].emplace_back(i+n);
		}
		for(int i=0;i<=10000000;i++){
			if(v[i].size()){
				sort(v[i].begin(),v[i].end(),cmp);
				for(auto j:v[i]){
					if(j<=n) add(len[j].second.second+1,1);
					else ans[j-n]=ask(len[j].second.second+1);
				}
				for(auto j:v[i])
					if(j<=n) add(len[j].second.second+1,-1);
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	}
	else{
		for(int i=1;i<=n;i++) M[{s[i][1],s[i][2]}]++;
		string now1,now2;
		for(int i=1;i<=q;i++){
			int pos1=-1,pos2=-1;
			now1.clear(),now2.clear();
			for(int j=0;j<t[i][1].length();j++){
				if(t[i][1][j]!=t[i][2][j]){
					if(pos1<0) pos1=j;
					pos2=j;
				}
			}
			if(pos1<0) pos1=t[i][1].length()-1,pos2=0;
			long long ans=0;
			for(int l=0;l<=pos1;l++){
				now1.clear(),now2.clear();
				for(int j=l;j<max(pos2,l);j++) now1.push_back(t[i][1][j]),now2.push_back(t[i][2][j]);
				for(int r=max(pos2,l);r<t[i][1].length();r++){
					now1.push_back(t[i][1][r]);
					now2.push_back(t[i][2][r]);
					ans+=M[{now1,now2}];
				}
			}
			cout<<ans<<'\n';
		}
	}
}
