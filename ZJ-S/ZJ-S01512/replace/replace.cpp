#include<bits/stdc++.h>
using namespace std;
string a[200005]={},b[200005]={},s1,s2;
long long n,q,l,r;
int mm=(-1<<30),ll;
string ks(string s,int x,int y){
	string ss="";
	for (int i=x;i<=y;i++) ss+=s[i];
	return ss;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {cin>>a[i]>>b[i];ll=a[i].length();mm=max(mm,ll);}
	for (int x=0;x<q;x++){
		cin>>s1>>s2;long long s=0;
		if (s1.length()!=s2.length() or s1==s2){cout<<0<<endl;continue;}
		for (int i=0;i<s1.length();i++) if (s1[i]!=s2[i]) {l=i;break;}
		for (int i=s1.length()-1;i>=0;i--) if (s1[i]!=s2[i]) {r=i;break;}
		if ((r-l+1)>mm){cout<<0<<endl;continue;}
		for (int i=1;i<=n;i++){
			if (ks(s1,l,r)==a[i] and ks(s2,l,r)==b[i]) s+=1;
			else if (s1.length()<=a[i].length()){
				int l=s1.length()-a[i].length();
				for (int j=0;j<=l;j++){
					if (ks(s1,j,j+a[i].length()-1)==a[i] and ks(s2,j,j+a[i].length()-1)==b[i]) s+=1;
				}
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}



