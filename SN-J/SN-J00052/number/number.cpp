#include<bits/stdc++.h>
using namespace std;
string a;
int cnt=0;
priority_queue<char> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			pq.push(a[i]);
			cnt++;
		}
	}
	if(pq.top()=='0'){
		cout<<"0"<<endl;
	}
	for(int i=1;i<=cnt;i++){
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
