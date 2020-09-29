#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

int get_max(int *amount ,int n){

	int mxCredit=0 ;

	for(int i=0;i<n;i++){

		if(amount[mxCredit]<amount[i]){
			mxCredit=i ;
		}

	}

	return mxCredit ;

}

int get_min(int *amount,int n){

	int mxDebit=0 ;
	for(int i=0;i<n;i++){

		if(amount[mxDebit]>amount[i]){
			mxDebit=i ;
		}
	}

	return mxDebit ;

}

void minCostFlowRecur(int *amount,int n){

	int mxCredit=get_max(amount,n) ;
	int mxDebit=get_min(amount,n) ;

	if(amount[mxDebit]==0 && amount[mxCredit]==0)
		return ;

	int min2=min(-amount[mxDebit],amount[mxCredit]) ;

	amount[mxCredit]-=min2 ;
	amount[mxDebit]+=min2 ;

	cout<<"Person "<<mxDebit<<" pays "<<min2<< " to "<<"Person "<<mxCredit<<"\n"; 

	minCostFlowRecur(amount,n) ;

}

void minCostFlow(vector<vector<int>> &adj,int n){

	int amount[n]={0} ;

	for(int p=0;p<n;p++){
		for(int i=0;i<n;i++){

			amount[p]+=(adj[i][p]-adj[p][i]) ;
		}
	}

	minCostFlowRecur(amount,n) ;

}


void solve(){

	//n--number of people 
	//t-number of transcation

	int n,t ;
	cin>>n>>t ;

	vector<vector<int>> adj(n,vector<int>(n)) ;

	for(int i=0;i<t;i++){

		int x,y,m ;
		cin>>x>>y>>m ;
		adj[x][y]=m ;

	}	

	minCostFlow(adj,n) ;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}