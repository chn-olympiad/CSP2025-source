#include<bits/stdc++.h>
using namespace std;
long long a,s,d[500005],qjh[500005];
map<long long,long long> m,n;
stack<long long> st;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>s;
	for(int z=1; z<=a; z++){
		cin>>d[z];
	}
	for(int z=0; z<=a; z++){
		qjh[z]=(qjh[z-1]^d[z]);
		if(m.find(qjh[z]^s)!=m.end()&&n.find(m[qjh[z]^s])==n.end()){
			n[m[qjh[z]^s]]=z;
			//cout<<m[qjh[z]^s]<<" "<<z<<endl;
		}
		m[qjh[z]]=z+1;
	}
	//cout<<endl;
	for(int z=1; z<=a; z++){
		if(n.find(z)!=n.end()){
			if(st.empty()){
				st.push(n[z]);
			}
			else{
				if(z>st.top()){
					st.push(n[z]);
				}
				else if(n[z]<=st.top()){
					st.pop();
					st.push(n[z]);
				}
			}
		}
	}
	cout<<st.size();
	return 0;
} 

