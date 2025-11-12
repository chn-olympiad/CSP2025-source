#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int qi[200005];
int h[200005];
int z[200005];
void scan(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		qi[i]=s[i][0].find("b");
		h[i]=s[i][0].length()-qi[i]-1;
		int taim=s[i][1].find("b");
		z[i]=qi[i]-taim;
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scan();
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<endl;
			continue;
		}else{
			int cnt=0;
			int posi=s1.find("b");
			int qian=posi;
			int hou=s1.length()-posi-1;
			int aim=s2.find("b");
			int zuoyi=posi-aim;
			for(int j=1;j<=n;j++){
				if(qi[j]>qian){
					continue;
				}
				if(h[j]>hou){
					continue;
				}
				if(zuoyi==z[j]){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

/*
3 4
ab ba
abaaaaaa aabaaaaa
baa ab
aaabaaaa aaaabaaa
baaaaaaa aaaaaaab
ba       ab
abaaa aabaa

*/
