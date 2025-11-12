#include<bits/stdc++.h>
using namespace std;

const int N=100001;
string st,en;
int n,T;
struct node{
	string s1,s2;
}a[N];
string split(string q,int stt,int l){
	string ans;
	for(int i=stt;ans.size()<l;i++){
		if(i>=q.size())return ans;
		ans+=q[i];
	}
	return ans;
}
bool judge(string q,string p,string startt,string endd){
	for(int i=0;i<startt.size();i++){
		if(split(startt,i,q.size())==q){
			string pp=split(startt,0,i)+p+split(startt,i+q.size(),startt.size());
			if(pp==endd)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(T--){
		cin>>st>>en;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(judge(a[i].s1,a[i].s2,st,en)){
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
