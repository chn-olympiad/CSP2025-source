#include<bits/stdc++.h>
using namespace std;
int a[5001];
int n;
vector<int> l;
vector<vector<int> >len;
int back(int start){
	if(l.size()>=3){
		len.push_back(l);
	}
	for(int i=start;i<=n;i++){
		l.push_back(a[i]);
		back(i+1);
		l.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	back(1);
	long long int s=0;
	for(int j=0;j<len.size();j++){
		int slen=0;
		for(int i=0;i<len[j].size();i++){
			slen+=len[j][i];
		}
		if(slen>len[j].back()*2){
			s++;
		}
	}
	cout<<s%(998*244*353);
	return 0;
}
