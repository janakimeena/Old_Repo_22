#include<iostream>
using namespace std;
#include<list>
#include<map>
#include<queue>
#include<limits.h>
struct node
{
    string name;
    int distance;
    bool operator<(const node&) const;
    bool operator==(const node&) const;
};
struct table_details
{
    bool visited;
    int distance;
    string thro_vertex;
};
void print_dij_table(map<string,table_details> dij_table);
bool node::operator<(const node& a) const
{
    return distance>a.distance;
}
bool node::operator==(const node& a) const
{
    return name==a.name;
}
void print_graph(const map<string,list<node> > &graph)
{
    for(auto vertex:graph)
    {
        cout<<vertex.first<<endl;
        for(auto node:vertex.second)
        {
            cout<<node.name<<" "<<node.distance<<" ";
        }
        cout<<endl;
    }
}
int is_adjacent(string vertex,list<node> adj_nodes)
{
    for(auto node:adj_nodes)
    {
 //       cout<<node.name<<" "<<node.distance<<endl;
        if(vertex==node.name)
            return node.distance;
    }
    return 0;
}
void first_step(map<string,list<node> > graph,map<string,table_details> &dij_table,vector<string> vertices,priority_queue<node> &Q, string start)
{
    list<node> adj_nodes;   
    int distance;
    adj_nodes = graph[start];
    dij_table[start].visited = true;
    for(auto v:vertices)
    { 
        node new_node;
        if(v==start)
            continue;
        new_node.name=v;        
        distance = is_adjacent(v,adj_nodes);
        if(distance)
        {            
            new_node.distance=distance;      
            dij_table[v].distance = distance;
            dij_table[v].thro_vertex = start;
        }
        else
        {
            new_node.distance = INT_MAX;
        }
        Q.push(new_node);
    }
}
void repeated_steps(map<string,list<node> > graph,map<string,table_details> &dij_table,vector<string> vertices,priority_queue<node> &Q,string start)
{
    
    node min_node,new_node;
    list<node> adj_nodes;
    string curr_node;
    while(!Q.empty())
    {
        min_node = Q.top();
        Q.pop();
        if(dij_table[min_node.name].visited==true)
            continue;
        cout<<"Next update "<<endl;
        print_dij_table(dij_table);
        cout<<endl;
        // make current node as min node
        curr_node = min_node.name;
        // mark it as visited
        dij_table[curr_node].visited = true;
        // take all adjacent nodes
        adj_nodes = graph[curr_node];
        // update dij table
        for(auto node:adj_nodes)        
        {
            if(node.name==start)
                continue;
            cout<<"Node is "<<min_node.name<<" DIstance in PQ "<<min_node.distance<<endl;
            if(dij_table[node.name].distance>(dij_table[curr_node].distance+node.distance))
            {
                dij_table[node.name].distance = dij_table[curr_node].distance+node.distance;
                dij_table[node.name].thro_vertex = curr_node; 
                // insert into priority queue if weight is updated
                new_node.name = node.name;
                new_node.distance = dij_table[curr_node].distance+node.distance;
                Q.push(new_node);
            }
        }
       
    }

}
void initialize_dij_table(map<string, table_details > &dij_table,vector<string> vertices,string start)
{
    table_details t;
    t.visited = false;
    t.distance = 0;
    t.thro_vertex = " ";
    dij_table[start] = t;
    t.distance = INT_MAX;
    for(auto v:vertices)
    {
        if(v==start)
            continue;
        dij_table[v] = t;
    }
}
void print_dij_table(map<string,table_details> dij_table)
{
    table_details detail;
    for (auto row: dij_table)
    {
        cout<<row.first<<" ";
        detail = row.second;
        cout<<detail.visited<<" ";
        cout<<detail.distance<<" ";
        cout<<detail.thro_vertex<<endl;
    }
}
int main()
{
    map<string,list<node> > graph;
    map<string, table_details> dij_table;
    vector<string> vertices;
    priority_queue<node> Q;
    int num_vertices,i,j,num_adj_ver;
    node adj_vertex;
    string name,start;
    cout<<"Enter number of vertices";
    cin>>num_vertices;
    for(i=0;i<num_vertices;i++)
    {
        cout<<"Enter name and num of adjacent vertices";
        cin>>name;
        cin>>num_adj_ver;
        list<node> adj_list;
        for(j=0;j<num_adj_ver;j++)
        {            
            cin>>adj_vertex.name>>adj_vertex.distance;
            adj_list.push_back(adj_vertex);
        }
        graph[name] = adj_list;
        vertices.push_back(name);
    }
    //print_graph(graph);
    cout<<"Enter start node";
    cin>>start;
    initialize_dij_table(dij_table,vertices,start);
    cout<<"Initial dij table"<<endl;
    print_dij_table(dij_table);
    cout<<endl;
    first_step(graph,dij_table,vertices,Q,start);    
    repeated_steps(graph,dij_table,vertices,Q,start);
    print_dij_table(dij_table);
 //   cout<<Q.top().name<<" "<<Q.top().distance<<endl;
}