#include<bits/stdc++.h>

using namespace std;

int main(){
//刘家豪 SN-00096 延安市新区第三中学
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,d=" ";
	cin>>s;
		priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' && d==" ")
			d.push_back(s[i]);
		else if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' && d!=" ")
			if(s[i]>d[0])
				d.push_back(s[i]);
			else
				d.push_back(s[i]);
	}
	for(int i=0;i<=d.size();i++){
		pq.push(d[i]);
	}
	cout<<pq.top();
		for(int i=0;i<=d.size();i++){
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

