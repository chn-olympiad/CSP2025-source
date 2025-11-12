#include<bits/stdc++.h>
using namespace std;

string a;
priority_queue<char>q;
string c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int sum = 0;
	for(int i = 0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			q.push(a[i]);
			sum++;
		}
	}
	for(int i = 1;i<=sum;i++){
		c+=q.top();
		q.pop();
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
