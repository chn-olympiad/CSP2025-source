#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1;string s2;
}b,a[200002];
int n,q,ans;
void change(string&x,string&y){
	int j=0;
	while(j<x.size()&&x[j]==y[j])j++;
	x=x.substr(j-1);y=y.substr(j-1);
	j=y.size();
	while(j>=0&&y[j]==x[j])j--;
	y=y.substr(0,j+1);x=x.substr(0,j+1);
}
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
		change(a[i].s1,a[i].s2);
	}
	while(q--){
		cin>>b.s1>>b.s2;ans=0;
		change(b.s1,b.s2);
		for(int i=0;i<n;i++){
			if(a[i].s1==b.s1&&a[i].s2==b.s2)ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);return 0;
}