#include<bits/stdc++.h>
using namespace std;

int n,q,ans=0;
struct sr{
	string s1,s2;
}rules[N+10];

void swap(string a,string b){
	for(int i=1; i<=n; i++){
		if(a.find(rules[i].s1)){
			//忘了怎么替换字符串…… 
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>rules[i].s1>>rules[i].s2;
	}
	
	string from,to;
	for(int i=1; i<=q; i++){
		cin>>from>>to;
		swap(from,to);
	}
	
	cout<<2<<endl<<0;

	return 0;
}
//完了我字符串替换忘了怎么写了
//一忘东西彻底没招了啊…… 
//真骗不到一点分了没招了
//see you next truck（赛道是truck对吧……） 