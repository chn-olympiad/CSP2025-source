#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}
signed main(){
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		int c1,c2,c3;
		c1=c2=c3=0;
		cin>>n;
		int b[n+2][4];
		short mx[n+2];
        short mx3[n+2];
        short mb[n+2];
        vector<int> mv12,mv13,mv23;
        bool ok[n+2];
        short mxx[n+2];
		vector<pair<int,int> > lk1,lk2,lk3;
		for(int i = 0; i < n; i++){
            ok[i]=0;
			cin>>b[i][0]>>b[i][1]>>b[i][2];
            int aaa[3]={b[i][0],b[i][1],b[i][2]};
            sort(aaa,aaa+3);
            if(aaa[1]==b[i][0]){
                mx[i]=1;
            }
            else{
                if(aaa[1]==b[i][1]){
                    mx[i]=2;
                }
                else{           
                    mx[i]=3;
                }
            }
			if(b[i][0]>b[i][1]){
				if(b[i][0]>b[i][2]){
                    mxx[i]=0;
					b[i][3]=b[i][0];
					lk1.push_back({i,b[i][3]});
				}
				else{
                    mxx[i]=2;
					b[i][3]=b[i][2];
					lk3.push_back({i,b[i][3]});
				}
			}
			else{
				if(b[i][1]>b[i][2]){
                    mxx[i]=1;
					b[i][3]=b[i][1];
					lk2.push_back({i,b[i][3]});
				}
				else{
                    mxx[i]=2;
					b[i][3]=b[i][2];
					lk3.push_back({i,b[i][3]});
				}
			}
            if(mxx[i]==0){
                if(mx[i]==2){
                    mv12.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                }
                if(mx[i]==3){
                    mv13.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                }
            }
            else{
                if(mxx[i]==1){
                    if(mx[i]==1){
                        mv12.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                    }
                    if(mx[i]==3){
                        mv23.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                    }
                }
                else{
                    if(mx[i]==1){
                        mv13.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                    }
                    if(mx[i]==2){
                        mv23.push_back(b[i][mx[i]-1]-b[i][mxx[i]]);
                    }
                }
            }
		}
        sort(lk1.begin(),lk1.end(),cmp);
        sort(lk2.begin(),lk2.end(),cmp);
        sort(lk3.begin(),lk3.end(),cmp);
        int ans=0; 
        if(lk1.size()<=n/2){
            for(int i = 0; i < lk1.size(); i++){
                ok[lk1[i].first]=1;
                mb[lk1[i].first]=1;
                ans+=lk1[i].second;
            }
            c1+=lk1.size();
        }
        else{
            for(int i = 0; i < n/2; i++){
                ok[lk1[i].first]=1;
                mb[lk1[i].first]=1;
                ans+=lk1[i].second;
            }
            c1=n/2;
        }
        if(lk3.size()<=n/2){
            for(int i = 0; i < lk3.size(); i++){
                ok[lk3[i].first]=1;
                mb[lk3[i].first]=3;
                ans+=lk3[i].second;
            }
            c3+=lk3.size();
        }
        else{
            for(int i = 0; i < n/2; i++){
                ok[lk3[i].first]=1;
                mb[lk3[i].first]=3;
                ans+=lk3[i].second;
            }
            c3=n/2;
        }
        if(lk2.size()<=n/2){
            for(int i = 0; i < lk2.size(); i++){
                ok[lk2[i].first]=1;
                mb[lk2[i].first]=2;
                ans+=lk2[i].second;
            }
            c2+=lk2.size();
        }
        else{
            for(int i = 0; i < n/2; i++){
                ok[lk2[i].first]=1;
                mb[lk2[i].first]=2;
                ans+=lk2[i].second;
            }
            c2=n/2;
        }
        for(int i = 0; i < n; i++){
            if(!ok[i]){
                if(mx[i]==1){
                    if(c1<(n/2)){
                        ok[i]=1; 
                        ans+=b[i][0]; 
                        if(mxx[i]==1){
                        	mv12.push_back(b[i][1]-b[i][0]);
						}
						else{
							mv13.push_back(b[i][2]-b[i][0]);
						}
                    }
                }
                else{
                    if(mx[i]==2){
                        if(c2<(n/2)){
                            ok[i]=1;
                            ans+=b[i][1];
                            if(mxx[i]==0){
                                mv12.push_back(b[i][0]-b[i][1]);
                            }
                            else{
                                mv23.push_back(b[i][2]-b[i][1]);
                            }
                        }
                    }
                    else{
                        if(c3<(n/2)){
                            ok[i]=1;
                            ans+=b[i][2];
                            if(mxx==0){
                                mv13.push_back(b[i][0]-b[i][2]);
                            }
                            else{
                                mv23.push_back(b[i][1]-b[i][2]);
                            }
                        }
                    }
                }
            }
        }
        sort(mv12.begin(),mv12.end());
        sort(mv13.begin(),mv13.end());
        sort(mv23.begin(),mv23.end());
        int i=0,j=0;
        if(mv12.size()!=0){
        	while(mv12[i]<=0&&mv12[mv12.size()-1-j]>=0)
        	{
        		if(abs(mv12[i])<mv12[mv12.size()-1-j]){
        			ans+=mv12[i];
            		ans+=mv12[mv12.size()-1-j];
            		i++;j++;
				}
            	else{
            		i++;
				}
        	}
		}
        i=0;j=0;
        if(mv13.size()!=0){
        	while(mv13[i]<=0&&mv13[mv13.size()-1-j]>=0)
        	{
        		if(abs(mv13[i])<mv13[mv13.size()-1-j]){
        			ans+=mv13[i];
            		ans+=mv13[mv13.size()-1-j];
            		i++;j++;
				}
            	else{
            		i++;
				}
        	}
		}
        i=0;j=0;
        if(mv23.size()!=0){
        	while(mv23[i]<=0&&mv23[mv23.size()-1-j]>=0)
        	{
        		if(abs(mv23[i])<mv23[mv23.size()-1-j])
        		{
        			ans-=mv23[i];
            		ans+=mv23[mv23.size()-1-j];
            		i++;
            		j++;
				}
            	else{
            		i++;
				}
        	}
		}
        cout<<ans<<'\n';
	}
    return 0;
}