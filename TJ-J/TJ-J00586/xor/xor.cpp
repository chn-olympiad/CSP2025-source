#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,k,arr[N],bts[N][20],pre[N],cnt;

struct Node{
	int val,pos;
	friend bool operator<(const Node x,const Node y){
		if(x.val==y.val)return x.pos<y.pos;
		return x.val<y.val;
	}
};

struct node{
	int l,r;
	friend bool operator<(const node x,const node y){
		return x.r<y.r;
	}
}brr[N];

set<Node> st;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pre[i]=arr[i];
		arr[i]=arr[i] xor arr[i-1];
	}
	for(int i=n;i>=0;i--){
		if(st.size()){
			//cout<<lower_bound(st.begin(),st.end(),(Node){arr[i] xor k,1});
			set<Node>::iterator it=lower_bound(st.begin(),st.end(),(Node){arr[i] xor k,1});
			if(it!=st.end() && (*it).val==(arr[i] xor k)){
				brr[++cnt]=(node){i,(*it).pos};
			}
		}
		st.insert((Node){arr[i],i});
		//cout<<arr[i]<<endl;
	}
	sort(brr+1,brr+1+cnt);
	int last=brr[1].r,ans=1;
	//cout<<brr[1].l<<brr[1].r<<endl;
	for(int i=2;i<=cnt;i++){
		//cout<<brr[i].l<<' '<<brr[i].r<<endl;
		if(brr[i].l>=last){
			//cout<<'^';
			ans++;
			last=brr[i].r;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
	//freopen("text1.in","r",stdin);
	//freopen("1.out","w",stdout);
