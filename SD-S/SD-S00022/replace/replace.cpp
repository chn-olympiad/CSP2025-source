#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=5e6+10;
int n,q;
deque<char>s1,s2;
map<pair<deque<char>,deque<char> > ,int>mp;
void reads(deque<char> &s){
	s.clear();
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while('a'<=c&&c<='z'){
		s.push_back(c);
		c=getchar();
	}
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		reads(s1);
		reads(s2);
		while(s1.front()==s2.front()){
			s1.pop_front();
			s2.pop_front();
		}
		while(s1.back()==s2.back()){
			s1.pop_back();
			s2.pop_back();
		}
		if(s1.size()==0){
			continue;
		}
		mp[make_pair(s1,s2)]++;
	}
	while(q--){
		reads(s1);
		reads(s2);
		while(s1.front()==s2.front()){
			s1.pop_front();
			s2.pop_front();
		}
		while(s1.back()==s2.back()){
			s1.pop_back();
			s2.pop_back();
		}
		write(mp[make_pair(s1,s2)]);
		putchar('\n');
	}
	return 0;
}
