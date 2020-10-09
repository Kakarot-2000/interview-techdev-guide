// Finding an Euler Path
// T(n) : O(E)	S(n): O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define loop1(size) for(int i=0;i<size;i++)
vector<int> res;vector<int> in(100),out(100);
void add_edge(map<int,priority_queue<int,vector<int>,greater<int> > > &adj_list,int u,int v)
{
	adj_list[u].push(v);
}
int eulerPathExists(map<int,priority_queue<int,vector<int>,greater<int> > > adj_list,int size)
{
		for(int i=0;i<size;i++)
		{
			priority_queue<int,vector<int>,greater<int> > pq=adj_list[i];
			while(!pq.empty())
			{
				int u=pq.top();
				pq.pop();
				cout<<i<<" --> "<<u<<"\n";
				out[i]++;
				in[u]++;
			}
		}
		for(int i=0;i<size; i++)
		{
		    cout<<i<<" in : "<<in[i]<<" out : "<<out[i]<<"\n";
		}
		int start_nodes=0,end_nodes=0;
		for(int i=0;i<size;i++)
		{
			if(abs(out[i]-in[i])>1) return 0;
			if(out[i]-in[i]==1)
				start_nodes++;
			if(in[i]-out[i]==1)
				end_nodes++;
		}
		cout<<"START NODES : "<<start_nodes<<" end_nodes  : "<<end_nodes<<"\n";
		if((start_nodes==1 && end_nodes==1) || (start_nodes==0 && end_nodes==0))
			return 1;
		else
			return 0;
}
void dfs(int start,map<int,priority_queue<int,vector<int>,greater<int> > > &adj_list)
{
		priority_queue<int,vector<int>,greater<int> > &pq=adj_list[start];
		while(!pq.empty())
		{
		    	int u=pq.top();
		    	pq.pop();
				dfs(u,adj_list);
		}
		res.push_back(start);
}
void fun1(map<int,priority_queue<int,vector<int>,greater<int> > > adj_list,int size)
{
		if(!eulerPathExists(adj_list,size))
		{
		    cout<<"NOT POSSIBLE\n";
		}
		int start=0;	// default
		for(int i=0;i<size;i++)
		{
			if(out[i]-in[i]==1){
				start=i;
				break;
			}
			if(out[i]>0) start=i;
		}
		cout<<"START : "<<start<<"\n";
		dfs(start,adj_list);
		set<int> unvisited;
		loop1(size)
			unvisited.insert(i);
		reverse(res.begin(),res.end());
		// Add code to check for unconnected components. If found return not possible 
		for(int i=0;i<res.size();i++)
		{
			if(unvisited.find(res[i])!=unvisited.end())
				unvisited.erase(res[i]);
			//cout<<res[i]<<" ";
		}
		/*if(!unvisited.empty())	cout<<"NOT POSSIBLE\n";	// to check for disconnected components
		else
		{
			for(int i=0;i<res.size();i++)
				cout<<res[i]<<" ";
		}*/
		for(int i=0;i<res.size();i++)
				cout<<res[i]<<" ";
		cout<<"\n";
}
int main()
{
		int size,val;
		cout<<"ENTER SIZE : ";
		cin>>size;
		map<int,priority_queue<int,vector<int>,greater<int> > > adj_list;
		cout<<"ENTER ADJ MATRIX : \n";
		loop1(size)
		{
			for(int j=0;j<size;j++)
			{
				cin>>val;
				if(val!=0)
				{
					for(int k=0;k<val;k++)	// to accept multi edges 
						add_edge(adj_list,i,j);
				}
			}
		}
		fun1(adj_list,size);
}
