#include<bits/stdc++.h>
using namespace std;
int n_,m_,bj_,fs_,rs_;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n_>>m_;
	cin>>fs_;
	bj_=fs_;
	for(int i=1; i<=n_; i++){
		for(int j=1; j<=m_; j++){
			if(i==1&&j==1)continue;
			cin>>fs_;
			if(fs_>bj_)rs_++;
		}
	}
	rs_++;
	int ls_=rs_%n_,hs_;
	if(rs_%n_>0){
		hs_=rs_/n_+1;
	}
	else hs_=rs_/n_;
	if(ls_==0){
		ls_=n_;
	}
	if(hs_%2==0){
		ls_=n_-ls_+1;
	}
	cout<<hs_<<" "<<ls_;
	return 0;
}
