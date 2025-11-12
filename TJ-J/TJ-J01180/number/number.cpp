#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int n;
queue <int> q;
int main(){
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]+0;
			n++;
		}
	}
	for(int i=0;i<s.size();i++){
		int ans=0;
		for(int j=0;j<=s.size();j++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		q.push(ans);
	}
	if(s.size()==1){
		cout<<s;
	}else{
		while(!q.empty()&&!n){
			cout<<q.front();
			q.pop();
			n--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//( T^T)
