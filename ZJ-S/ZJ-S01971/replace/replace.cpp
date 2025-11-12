#include<bits/stdc++.h>
using namespace std;
string a[5000005],b[5000005],c,d;
int n,q;
map<int,int>mp,mp1,mp2,mp3,mp4,mp5;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[(a[i].find('a')-b[i].find('b'))*(a[i].find('d')-b[i].find('a'))-a[i].find('c')+b[i].find('d')]++;
		mp1[(a[i].find('d')-b[i].find('v'))*(a[i].find('t')-b[i].find('s'))-a[i].find('v')+b[i].find('a')]++;
		mp2[(a[i].find('a')-b[i].find('c'))*(a[i].find('e')-b[i].find('g'))-a[i].find('b')+b[i].find('t')]++;
		mp3[(a[i].find('x')-b[i].find('z'))*(a[i].find('t')-b[i].find('w'))-a[i].find('q')+b[i].find('m')]++;
		mp4[(a[i].find('n')-b[i].find('y'))*(a[i].find('q')-b[i].find('p'))-a[i].find('s')+b[i].find('n')]++;
		mp5[(a[i].find('p')-b[i].find('f'))*(a[i].find('j')-b[i].find('z'))-a[i].find('e')+b[i].find('r')]++;
	}
	while(q--){
		cin>>c>>d;
		if(c.size()!=d.size())cout<<"0\n";
		else{
			int m0=mp[(c.find('a')-d.find('b'))*(c.find('d')-d.find('a'))-c.find('c')+d.find('d')];
			int m1=mp1[(c.find('d')-d.find('v'))*(c.find('t')-d.find('s'))-c.find('v')+d.find('a')];
			int m2=mp2[(c.find('a')-d.find('c'))*(c.find('e')-d.find('g'))-c.find('b')+d.find('t')];
			int m3=mp3[(c.find('x')-d.find('z'))*(c.find('t')-d.find('w'))-c.find('q')+d.find('m')];
			int m4=mp4[(c.find('n')-d.find('y'))*(c.find('q')-d.find('p'))-c.find('s')+d.find('n')];
			int m5=mp5[(c.find('p')-d.find('f'))*(c.find('j')-d.find('z'))-c.find('e')+d.find('r')];
			cout<<min(m0,min(m1,min(m2,min(m3,min(m4,m5)))))<<'\n';
		}
	}
	return 0;
}
