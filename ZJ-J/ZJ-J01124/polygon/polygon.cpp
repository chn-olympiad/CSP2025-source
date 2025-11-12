#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,a[5005];
ll ans;
bool pan3(ll a,ll b,ll c) {
	ll he=a+b+c;
	return he>c*2;
}
bool pan4(ll a,ll b,ll c,ll d) {
	ll he=a+b+c+d;
	return he>d*2;
}
bool pan5(ll a,ll b,ll c,ll d,ll e) {
	ll he=a+b+c+d+e;
	return he>e*2;
}
bool pan6(ll a,ll b,ll c,ll d,ll e,ll f) {
	ll he=a+b+c+d+e+f;
	return he>f*2;
}
bool pan7(ll a,ll b,ll c,ll d,ll e,ll f,ll g) {
	ll he=a+b+c+d+e+f+g;
	return he>g*2;
}
bool pan8(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h) {
	ll he=a+b+c+d+e+f+g+h;
	return he>h*2;
}
bool pan9(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i) {
	ll he=a+b+c+d+e+f+g+h+i;
	return he>i*2;
}
bool pan10(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j) {
	ll he=a+b+c+d+e+f+g+h+i+j;
	return he>j*2;
}
bool pan11(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k) {
	ll he=a+b+c+d+e+f+g+h+i+j+k;
	return he>k*2;
}
bool pan12(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l;
	return he>l*2;
}
bool pan13(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m;
	return he>m*2;
}
bool pan14(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n;
	return he>n*2;
}
bool pan15(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o;
	return he>o*2;
}
bool pan16(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p;
	return he>p*2;
}
bool pan17(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q;
	return he>q*2;
}
bool pan18(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r;
	return he>r*2;
}
bool pan19(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r,ll s) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s;
	return he>s*2;
}
bool pan20(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r,ll s,ll t) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t;
	return he>t*2;
}
bool pan21(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r,ll s,ll t,ll u) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u;
	return he>u*2;
}
bool pan22(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r,ll s,ll t,ll u,ll v) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v;
	return he>v*2;
}
bool pan23(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j,ll k,ll l,ll m,ll n,ll o,ll p,ll q,ll r,ll s,ll t,ll u,ll v,ll w) {
	ll he=a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w;
	return he>w*2;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			for(int k=j+1; k<n; k++) {
				if(pan3(a[i],a[j],a[k]))ans=(ans+1)%mod;
				for(int x=k+1; x<n; x++) {
					if(pan4(a[i],a[j],a[k],a[x]))ans=(ans+1)%mod;
					for(int y=x+1; y<n; y++) {
						if(pan5(a[i],a[j],a[k],a[x],a[y]))ans=(ans+1)%mod;
						for(int z=y+1; z<n; z++) {
							if(pan6(a[i],a[j],a[k],a[x],a[y],a[z]))ans=(ans+1)%mod;
							for(int m=z+1; m<n; m++) {
								if(pan7(a[i],a[j],a[k],a[x],a[y],a[z],a[m]))
									ans=(ans+1)%mod;
								for(int p=m+1; p<n; p++) {
									if(pan8(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p]))
										ans=(ans+1)%mod;
									for(int q=p+1; q<n; q++) {
										if(pan9(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q]))
											ans=(ans+1)%mod;
										for(int e=q+1; e<n; e++) {
											if(pan10(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e]))
												ans=(ans+1)%mod;
											for(int b=e+1; b<n; b++) {
												if(pan11(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b]))
													ans=(ans+1)%mod;
												for(int c=b+1; c<n; c++) {
													if(pan12(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c]))
														ans=(ans+1)%mod;
													for(int d=c+1; d<n; d++) {
														if(pan13(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d]))
															ans=(ans+1)%mod;
														for(int l=d+1; l<n; l++) {
															if(pan14(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l]))
																ans=(ans+1)%mod;
															for(int o=l+1; o<n; o++) {
																if(pan15(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o]))
																	ans=(ans+1)%mod;
																for(int r=o+1; r<n; r++) {
																	if(pan16(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r]))
																		ans=(ans+1)%mod;
																	for(int u=r+1; u<n; u++) {
																		if(pan17(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u]))
																			ans=(ans+1)%mod;
																		for(int v=u+1; v<n; v++) {
																			if(pan18(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v]))
																				ans=(ans+1)%mod;
																			for(int w=v+1; w<n; w++) {
																				if(pan19(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v],a[w]))
																					ans=(ans+1)%mod;
																				for(int thelastone=w+1; thelastone<n; thelastone++) {
																					if(pan20(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v],a[w],a[thelastone]))
																						ans=(ans+1)%mod;
																					for(int fir=thelastone+1; fir<n; fir++) {
																						if(pan21(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v],a[w],a[thelastone],a[fir]))
																							ans=(ans+1)%mod;
																						for(int sec=fir+1; sec<n; sec++) {
																							if(pan22(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v],a[w],a[thelastone],a[fir],a[sec]))
																								ans=(ans+1)%mod;
																							for(int thir=sec+1; thir<n; thir++) {
																								if(pan23(a[i],a[j],a[k],a[x],a[y],a[z],a[m],a[p],a[q],a[e],a[b],a[c],a[d],a[l],a[o],a[r],a[u],a[v],a[w],a[thelastone],a[fir],a[sec],a[thir]))
																									ans=(ans+1)%mod;
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	cout<<ans;
	return 0;
}
