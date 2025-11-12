#include<bits/stdc++.h>
#define int long long
using namespace std;
struct zj_{
	int qd_,zd_;
}qj_[200005];
int n_,k_,cnt_,ans_,a_[200005],qzh_[200005];
bool pxpd_(zj_ yg_,zj_ lg_){
	return yg_.qd_<lg_.qd_;
}
void hs_(int now_,int e_,int gs_){
	if(now_==cnt_+1){
//	    cout<<gs_<<"\n";
		ans_=max(ans_,gs_);
		return;
	}
	if(e_>=qj_[now_].qd_){
//		cout<<e_<<" "<<qj_[now_].qd_<<"wsc";
		hs_(now_+1,e_,gs_);
	}
	else{
		int dddd_=qj_[now_].zd_;
		hs_(now_+1,dddd_,gs_+1);
		hs_(now_+1,e_,gs_);
	}
}
main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n_>>k_;
	for(int i=1; i<=n_; i++){
		cin>>a_[i];
		qzh_[i]=qzh_[i-1]^a_[i];
	}
	for(int i=1; i<=n_; i++){
		for(int j=i; j<=n_; j++){
			int cs_=qzh_[j]^qzh_[i-1];
			if(cs_==k_){
				qj_[++cnt_].qd_=i;
				qj_[cnt_].zd_=j;
//				cout<<cnt_<<" ";
//				cout<<i<<" "<<j<<" "<<cs_<<"\n";
			}
		}
	}
	sort(qj_+1,qj_+1+cnt_,pxpd_);
	hs_(1,0,0);
	cout<<ans_;
	return 0;
}
