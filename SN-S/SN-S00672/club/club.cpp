#include<bits/stdc++.h>
//SN-S00672 贾羽鹤 陕西省西安中学 
using namespace std;
struct qw{
	int a,b;//number,club;
};
struct qqq{
	qw a,b,c;
};
struct cmp{
	bool operator()(qqq a,qqq b){
		if(a.a.a!=b.a.a){
		//	cout<<endl<<a.a.a<<" "<<b.a.a<<endl;
			return a.a.a<b.a.a;
		}else if(a.b.a!=b.b.a){
		//	cout<<endl<<a.a.a<<" "<<b.a.a<<endl;
			return a.b.a<b.b.a;
		}else{
			//cout<<endl<<a.a.a<<" "<<b.a.a<<endl;
			return 0;
		}
		
	}
};
struct cmd{
	bool operator()(qw a,qw b){
		return a.a<b.a;
	}
};
priority_queue<qqq,vector<qqq>,cmp>qq;
priority_queue<qw,vector<qw>,cmd>qe;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int mm;
//	qqq a[3];
	cin>>mm;
	for(int mmm=0;mmm<mm;mmm++){
		int n;
		cin>>n;
		if(n==2){
			int a1,a2,a3,b1,b2,b3;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			cout<<max(a1+b2,max(a1+b3,max(a2+b1,max(a2+b3,max(a3+b1,a3+b2)))))<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			qw aa,bb,cc;
			cin>>aa.a>>bb.a>>cc.a;
			aa.b=1;bb.b=2;cc.b=3;
			qe.push(aa);
			qe.push(bb);
			qe.push(cc);
			qw aa1,bb1,cc1;
			aa1=qe.top();
			qe.pop();
			bb1=qe.top();
			qe.pop();
			cc1=qe.top();
			qe.pop();
		//	cout<<" "<<aa1.a<<bb1.a<<cc1.a<<endl;
			qq.push({aa1,bb1,cc1});
		}
		int a1[5]={0};
		long long ans=0;
		for(int i=0;i<n&&qq.size()>0;i++){
			qw aa,bb,cc;
			aa=qq.top().a;
			bb=qq.top().b;
			cc=qq.top().c;
			//cout<<"       "<<aa.a<<endl;
		//	cout<<aa.b<<"eeee"<<bb.b<<"eeee"<<cc.b<<" mm "<<endl;
			qq.pop();
		//	cout<<ans;
			if(a1[aa.b]<n/2){
				ans+=aa.a;
				a1[aa.b]++;
			}else if(a1[bb.b]<n/2){
				ans+=bb.a;
				a1[bb.b]++;
			}else{
				ans+=cc.a;
				a1[cc.b]++;
			}
		}
		cout<<ans<<endl;
	}
fclose(stdout);
	fclose(stdin);
	return 0;
} 
