#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,q;
string s[200010][2];
string l[200010][2];
ll in(string a,string b,string c,string d,string f,ll h,ll t){
	string tt,dd;
	ll k=0,h1,i=0;
	while(i<a.size()){
		h1=i;
		k=0;
		tt="";
		dd=d;
		while(a[i]==c[k]&&i<a.size()&&k<c.size()){
			tt+=a[i];
			i++;
			k++;
		}
		if(k!=0)i--;
		if(tt==c){
//			cout<<tt<<" ";
			if(d.size()-t-1<a.size()-h1-c.size()||h<h1)continue;
			for(int j=h-h1;j<=t+a.size()-h1-c.size();j++){
				dd[j]=b[j-h+h1];
			}
//			cout<<dd<"  ";
			if(dd==f){
				return 1;
			}
		}
		i++;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>l[i][0]>>l[i][1];
		if(l[i][0].size()!=l[i][1].size()){
			cout<<"0\n";
			continue;
		}
		ll j=0,flag=0,h,t;
		string s1="",s2="";
		while(j<l[i][0].size()){
			if(flag==2){
				break;
			}
			if(l[i][0][j]!=l[i][1][j]){
				flag++;
				h=j;
				while(j<l[i][0].size()&&l[i][0][j]!=l[i][1][j]){
					s1+=l[i][0][j];
					s2+=l[i][1][j];
					j++;
				}
				t=j-1;
				j--;
			}
			j++;
		}
//		cout<<s1<<" "<<s2<<" "<<flag<<" "<<h<<" "<<t<<" ";
		if(flag>1){
			cout<<"0\n";
			continue;
		}
		ll ans=0;
		for(int j=1;j<=n;j++){
			if(in(s[j][0],s[j][1],s1,l[i][0],l[i][1],h,t)){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
