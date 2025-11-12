#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7,x=13331,mod2=998244353,x2=131;
string s[40010][2],a,aa;
bitset<40010>c,d,e,f,g,c2,d2,e2;
map<int,bitset<40010>>mp1,mp2,mp3,mp12,mp22,mp32;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,h,b;
	ll num,num2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		h=0;
		b=s[i][0].size()-1;
		while(s[i][0][h]==s[i][1][h]&&h<=b){
			h++;
		}
		while(s[i][0][b]==s[i][1][b]&&b>=0){
			b--;
		}
		num=0;
		num2=0;
		if(h>b){
			h=0;
			b=-1;
		}
		for(int j=h;j<=b;j++){
			num=num*x+s[i][0][j]-'a'+1;
			num%=mod;
			num2=num2*x2+s[i][0][j]-'a'+1;
			num2%=mod2;
		}
		for(int j=h;j<=b;j++){
			num=num*x+s[i][1][j]-'a'+1;
			num%=mod;
			num2=num2*x2+s[i][1][j]-'a'+1;
			num2%=mod2;
		}
		mp1[num][i]=1;
		mp12[num2][i]=1;
		//cout<<num<<" ";
		num=0;
		num2=0;
		for(int j=h-1;j>=0;j--){
			num=num*x+s[i][0][j]-'a'+1;
			num%=mod;
			num2=num2*x2+s[i][0][j]-'a'+1;
			num2%=mod2;
		}
		mp2[num][i]=1;
		mp22[num2][i]=1;
		//cout<<num<<" ";
		num=0;
		num2=0;
		for(int j=b+1;j<s[i][0].size();j++){
			num=num*x+s[i][0][j]-'a'+1;
			num%=mod;
			num2=num2*x2+s[i][0][j]-'a'+1;
			num2%=mod2;
		}
		mp3[num][i]=1;
		mp32[num2][i]=1;
		//cout<<num<<"\n";
	}
	while(q--){
		c&=f;
		d&=f;
		e&=f;
		c2&=f;
		d2&=f;
		e2&=f;
		cin>>a>>aa;
		h=0;
		b=a.size()-1;
		while(a[h]==aa[h]&&h<=b){
			h++;
		}
		while(a[b]==aa[b]&&b>=0){
			b--;
		}
		num=0;
		num2=0;
		//cout<<h<<" "<<b<<"\n";
		for(int j=h;j<=b;j++){
			num=num*x+a[j]-'a'+1;
			num%=mod;
			num2=num2*x2+a[j]-'a'+1;
			num2%=mod2;
		}
		for(int j=h;j<=b;j++){
			num=num*x+aa[j]-'a'+1;
			num%=mod;
			num2=num2*x2+aa[j]-'a'+1;
			num2%=mod2;
		}
		//cout<<num<<" 1\n";
		c=mp1[num];
		c2=mp12[num2];
		num=0;
		num2=0;
		d|=mp2[num];
		d2|=mp22[num2];
		//cout<<num<<" 2\n";
		for(int j=h-1;j>=0;j--){
			num=num*x+a[j]-'a'+1;
			num%=mod;
			d|=mp2[num];
			num2=num2*x2+a[j]-'a'+1;
			num2%=mod2;
			d2|=mp22[num2];
			//cout<<num<<" 2\n";
		}
		num=0;
		e|=mp3[num];
		num2=0;
		e2|=mp32[num2];
		//cout<<num<<" 3\n";
		for(int j=b+1;j<a.size();j++){
			num=num*x+a[j]-'a'+1;
			num%=mod;
			e|=mp3[num];
			num2=num2*x2+a[j]-'a'+1;
			num2%=mod2;
			e2|=mp32[num2];
			//cout<<num<<" 3\n";
		}
		g=c&d&e&d2&e2&c2;
		cout<<g.count()<<"\n";
	}
	return 0;
}