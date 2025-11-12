#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a,b,c,x[27][200010][2],l,l2;
int n,q,w[27],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>l>>l2;
		x[l[0]-'a'][w[l[0]-'a']][0]=l;
		x[l[0]-'a'][w[l[0]-'a']][1]=l2;
		w[l[0]-'a']++;
	}
	for(int i=0;i<q;i++){
		cin>>a>>b;
		ans=0;
		for(int j=0;a[j];j++){
			int p=a[j]-'a';
			for(int k=0;k<w[p];k++){
				int y=1,e=0;
				for(e=0;x[p][k][0][e];e++){
					if(x[p][k][0][e]!=a[j+e]||x[p][k][1][e]!=b[j+e]){
						y=0;
						break;
					}
				}
				if(a[e+j]!=b[e+j]||(a[j-1]!=b[j-1]&&j!=0)){
					y=0;
				}
				if(y==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
