#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct node {
	string s1,s2;
} s[100005];

string q1,q2;

int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i].s1 >>s[i].s2 ;
	}
	for(int i=1; i<=q; i++) {
		int cnt=0;
		cin>>q1 >>q2 ;
		for(int i=0; i<n; i++) {
			if(s[i].s1 .size()==q1.size() ) {
				int f=0;
				for(int j=0; j<q2.size(); j++) {
					
					if(s[i].s2 [i]!=q2[i]) {
						f=1;
						//cout<<"x///////////////////////////////////";
					}
				}
				if(f==0) {
					cnt++;
					//cout<<"///////////////////////////////////";
				}
			}
		}
		
		cout<<cnt<<endl;
	}

	return 0;
}

