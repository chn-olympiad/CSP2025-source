#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1,s2;
	int len;
}a[200005];
void solve1(string t1,string t2){
	int cnt=0;
	int nn =t1.size();
	for(int i=1;i<=n;i++){
		for(int j=0;j<nn-a[i].len+1;j++){
			if(t1.substr(j,a[i].len)==a[i].s1){
				string tt = t1.substr(0,j)+a[i].s2+t1.substr(j+a[i].len,nn-a[i].len-j);
				//cout<<tt<<endl;
				if(tt==t2)cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].len = a[i].s1.size();
	}
	int F=0;
	if((n<=100&&q<=100)||q==1)F=1;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(F==1){
			solve1(t1,t2);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
