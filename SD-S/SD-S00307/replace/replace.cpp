#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define sdn cout
#define pb push_back
using namespace std;
const int N = 2e5 + 10,INF = 1e9 + 7,base = 133;
const ull Mod = 1e9 + 7;
string s1[N],s2[N];
int n,q,ans;
ull h[N];
int L[N],R[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i ++){
		cin>>s1[i]>>s2[i];
		int len = s1[i].length();
		int l=len-1,r = 0;
		for(int j = 0;j < len;j ++){
			if(s1[i][j] != s2[i][j]){
			l = j;break;
			}
		}
		for(int j = len-1;j >= 0;j --){
			if(s1[i][j] != s2[i][j]){
				r = j;break;
			}
		}
		L[i] = l,R[i] = r;
		for(int j = l;j <= r;j ++){
			h[i] = (h[i]*base+(ull)(137*s1[i][j]+651*s2[i][j]))%Mod;
		}
	}
	while(q--){
		string s11,s22;cin>>s11>>s22;int len = s11.length();ans = 0;
		ull hh = 0;
		int l=len-1,r = 0;
		for(int j = 0;j < len;j ++){
			if(s11[j] != s22[j]){
			l = j;break;
			}
		}
		for(int j = len-1;j >= 0;j --){
			if(s11[j] != s22[j]){
				r = j;break;
			}
		}
		for(int i = l;i <= r;i ++){
			hh = (hh*base+(ull)(137*s11[i]+651*s22[i]))%Mod;
		}
		for(int i = 1;i <= n;i ++){
			if(L[i] > l || s1[i].length()-R[i] > len-r)  continue;
			bool ff = 1;int len1 = s1[i].length(),cha = l-L[i];
			if(h[i] == hh){
				for(int j = L[i]-1;j >= 0;j --){
					if(s1[i][j] != s11[j+cha]){
						ff = 0;break;
					}
				}
				for(int j = R[i]+1;j < len1;j ++){
					if(s1[i][j] != s11[j+cha]){
						ff = 0;break;
					}
				}
			}
			else  ff = 0;
			if(ff)  ans ++,sdn<<s1[i]<<endl;
		}
		sdn<<ans<<endl;
	}
	return 0;
}
