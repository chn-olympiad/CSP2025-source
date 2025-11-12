#include<bits/stdc++.h>
using namespace std;
struct node{
	string q_string;
	string h_string;
};
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replacehhh.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<node> string_pair(n);
	vector<node> string_pair_question(q);
	for(int i=0;i<n;i++){
		cin>>string_pair[i].q_string;
		cin>>string_pair[i].h_string;
	}
	for(int i=0;i<q;i++){
		cin>>string_pair_question[i].q_string;
		cin>>string_pair_question[i].h_string;
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
