# include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
string s;
ll a[N],b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    ll n=0;
    for(ll i=0; i<=s.size()-1; i++){
        a[i]=s[i]-'0';
		n++;

    }
    for(ll i=0; i<=s.size()-1; i++){
		for(ll j=0; j<=s.size()-1; j++){
			if(a[i]>a[j]){
				ll x=a[i],y=a[j];
				a[i]=y,a[j]=x;
			}
    	}
    }
    for(ll i=0; i<=s.size()-1; i++){
		cout<<a[i];
    }
    return 0;
}