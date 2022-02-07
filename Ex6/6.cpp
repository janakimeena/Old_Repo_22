#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
//  1 5 8 9 10 17 17 20 24 30
// 1 5 8 9 10 17 17 20 21 23
int maximum(int a, int b)
{   
    if(a>b)
        return a;
    return b;
}
void print_sizes(vector<pair<int,int> > &v, int length)
{
 
 int i;
 if(v[length-1].second==0) 
 {
     cout<<v[length-1].first<<" ";
    return;
 }
cout<<v[length-1].first<<" ";
print_sizes(v,v[length-1].second);

}
int bottom_up_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,0);
    pair<int,int> one_split(0,0);
    vector<pair<int,int> > splits(100,one_split);    
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        for(i=1;i<=j;i++)
        {
            //q = maximum(q,p[i-1]+r[j-i]);
            if( (q==INT_MIN) || (p[i-1]+r[j-i]>q))
            {                
                splits[j-1].first = i;
                splits[j-1].second = j-i;                
                q = p[i-1] + r[j-i];
            }
            //splits.push_back(one_split);
        }
        r[j] = q;
    }
    for(i=0;i<length;i++)
        cout<<splits[i].first<<" "<<splits[i].second<<endl;
    print_sizes(splits,length);
    return r[length];
}

int main()
{
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    max_profit = bottom_up_cut_rod(p,n);
    cout<<max_profit;
}
