#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 2e5+50;
const int ha = 998244353;
using namespace std;
int n,m,num;
string s[N],s1[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>s[i] >>s1[i];
	}
	for(int i=1;i<=m;i++){
		int num=0;
		string ans1,ans2;
		cin >>ans1 >>ans2;
		for(int j=1;j<=n;j++){
			string keep="";
			int lt=ans1.find(s[j]);
			if(lt<ans1.size()){
				for(int k=lt;k<lt+s1[j].size();k++){
					keep+=ans1[k];
					ans1[k]=s1[j][k-lt];
				}
				if(ans1==ans2){
					num++;
				}
//				cout <<ans1 <<endl;
				for(int k=lt;k<lt+s1[j].size();k++){
					ans1[k]=keep[k-lt];
				}
//				cout <<ans1 <<endl <<endl;
			}
		}
		cout <<num <<endl;
	}
	return 0;
}
