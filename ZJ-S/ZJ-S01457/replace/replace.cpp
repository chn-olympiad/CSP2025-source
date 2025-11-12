#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s1[N],s2[N];
int l[N];
int len;
void kmp(string a,string b){
	int l1=a.length(),l2=b.length();
	for(int i=0;i<l1;i++){
		string c=a.substr(i,l2);
		if(c==b){
			l[++len]=i;
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1;
		cin>>t2;
		if(t1.length()!=t2.length()){
			printf("0\n");
			continue;
		}
		len=0;
		int ans=0;
		for(int j=1;j<=n;j++){
			len=0;
			kmp(t1,s1[j]);
			for(int k=1;k<=len;k++){
				int ll=s1[j].length();
				string a=t1.substr(0,l[k]),b=t1.substr(l[k]+ll,t1.length()-(l[k]+ll));
				string p=a+s2[j]+b;
				if(p==t2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}