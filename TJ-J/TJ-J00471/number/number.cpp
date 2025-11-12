#include<bits/stdc++.h>
using namespace std;
int m[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int m_=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' and n[i]<='9'){
			m[m_]=(n[i]-'0');
			m_++;
		}
	}
	sort(m,m+m_);
	for(int i=m_-1;i>=0;i--){
		cout<<m[i];
	}
	return 0;
}
