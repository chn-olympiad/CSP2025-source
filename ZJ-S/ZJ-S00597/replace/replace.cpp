#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
string ss[200005];
bool check(string a,string b,string c){
	int la=a.length(),lb=b.length();
	if (la>lb)
		return 0;
	for (int i=0;i<la;i++)
		if (a[i]!=b[i])
			return 0;
	for (int i=la;i<lb;i++)
		if (c[i]!=b[i])
			return 0;
	return 1;
}
long long peidui (string a,string b){
	int la=a.length(),lb=b.length();
	long long cnt=0;
	if (la!=lb)
		return 0;
	string c="";
	for (int i=0;i<la;i++){
		for (int j=1;j<=n;j++)
			if (a[i]==ss[j][0]){
				if (check(c+mp[ss[j]],b,a))
					cnt++;
			}
		c+=a[i];
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a]=b;
		ss[i]=a;
	}
	for (int i=1;i<=q;i++){
		cin>>a>>b;
		cout<<peidui(a,b)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
