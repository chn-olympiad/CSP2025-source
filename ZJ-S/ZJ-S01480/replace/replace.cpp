#include<bits/stdc++.h>
using namespace std;
pair<string,string> nosame(string a,string b){
	int n=a.size();
	string c;
	string d;
	bool ok=0 ;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]||ok){
			c=c+a[i];
			d=d+b[i];
			ok=1;
		}
	}
	a=c,b=d,c="",d="";
	ok=0;
	n=a.size();
	for(int i=n-1;i>=0;i--){
		if(a[i]!=b[i]||ok){
			ok=1;
			c=c+a[i];
			d=d+b[i];
		}
	}
	a=c,b=d,c="",d="";
	n=a.size();
	for(int i=n-1;i>=0;i--){
		c=c+a[i];
		d=d+b[i];
	}
	return make_pair(c,d);
}
vector<string> vec1,vec2,vec3,vec4;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		pair<string,string> s=nosame(s1,s2);
		s1=s.first;s2=s.second;
		vec1.push_back(s1);
		vec2.push_back(s2);
	}
	
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		pair<string,string> s=nosame(s1,s2);
		s1=s.first;s2=s.second;
		int len=vec1.size(),ans=0;
		vec3.push_back(s1);
		vec4.push_back(s2);
		for(int j=0;j<len;j++){
			if(vec1[j]==vec3[i-1]&&vec2[j]==vec4[i-1]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

