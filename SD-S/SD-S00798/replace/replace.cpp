#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> sp[200005];
string s1[200005],s2[200005];
void QIUSP(string s,int x){
	sp[x].push_back(-1);
	sp[x].push_back(0);
	for(int i=2;i<s.size();i++){
		if(s[sp[x][i-1]+1]==s[i])sp[x][i]=sp[x][i-1]+1;
		else {
			int j=i-1;
			while(s[sp[x][j]+1]!=s[i]&&j!=0){
				j=sp[x][j];
			}
			sp[x][i]=sp[x][j]+1;
		}
	}
}
int n,q;
bool KMP(int x,string u,string v,int mn,int mx){
	for(int i=1,j=1;i<u.size();i++,j++){
		if(s1[x][j]==u[i]){
			if(j==s1[x].size()-1){
				if(i<mx||i-j+1>mn){
					j=sp[x][j];
				}
				else {
					for(int k=i-j+1,l=1;k<=i,l<s2[x].size();k++,l++){
						if(s2[x][l]!=v[k])return 0;	
					}
					return 1;
				}
			}
		}
		else {
			j-=1;
			j=sp[x][j];
			while(s1[x][j+1]!=u[i]&&j!=-1){
				j=sp[x][j];
			}
			j++;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		QIUSP(s1[i],i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<s1[i].size();j++){
////			cout <<"???";
//			cout << sp[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int a=1;a<=q;a++){
		int cnt=0;
		string u,v;
		cin >> u >> v;
		u=" "+u;v=" "+v;
		int flag=0,mn,mx;
		for(int i=1;i<u.size();i++){
			if(v[i]!=u[i]){
				mx=i;
				if(flag==0){
					mn=i;
					flag=1;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(KMP(j,u,v,mn,mx))cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
