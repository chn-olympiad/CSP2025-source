//by snakeMC
//now:AC
#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
priority_queue<char,vector<char>,less<char> >pq;
string c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	int l=c.length();
	for(int i=0;i<l;i++){
		if(c[i]>='0'&&c[i]<='9'){
			pq.push(c[i]);
		}
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
