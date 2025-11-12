#include<bits/stdc++.h>
using namespace std;
int n,q;unsigned long long vec[5000005][2];
unsigned long long hsh[400005][2];
unsigned long long Pow[5000005];
int siz[200005];
void inithsh(string &s,int pos2){
	vec[0][pos2]=s[0]-'a';
	for(int i=1;i<s.size();i++)vec[i][pos2]=vec[i-1][pos2]*29+(s[i]-'a');
}
void inithsh1(string &s,int pos1,int pos2){
	for(int i=0;i<s.size();i++)hsh[pos1][pos2]=hsh[pos1][pos2]*29+s[i]-'a';
}
unsigned long long query(int pos2,int l,int r){
	if(l>r)return 0;
	if(l==0)return vec[r][pos2];
	return vec[r][pos2]-Pow[r-l+1]*vec[l-1][pos2];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	int len=0;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		len=max((int)s1.size(),len);
		siz[i]=s1.size();
		inithsh1(s1,i,0);
		inithsh1(s2,i,1);
	}
	Pow[0]=1;
	for(int i=1;i<=5000000;i++)Pow[i]=Pow[i-1]*29;
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		inithsh(t1,0);
		inithsh(t2,1);
		int ans=0;
		for(int j=0;j<t1.size();j++){
			if(query(0,0,j-1)==query(1,0,j-1)){
				for(int k=1;k<=n;k++){
					if(j+siz[k]-1<t1.size()&&
					   query(0,j,j+siz[k]-1)==hsh[k][0]&&hsh[k][1]==query(1,j,j+siz[k]-1)&&
					   (j+siz[k]<t1.size()?query(0,j+siz[k],t1.size()-1)==query(1,j+siz[k],t1.size()-1):1))
						ans++;
				}
			}
			else break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//18:14 25pts
