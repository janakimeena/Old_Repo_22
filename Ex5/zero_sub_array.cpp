#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<limits.h>
struct details
{
    int low;
    int high;
};
details find_zero_sum(vector<int> elements)
{
    // store the sum of 'i' elements as key and value of 'i' as value
    // in a map
    map<int,int> sum_index;
    int i,n,sum=0;
    details d;
    n = elements.size();
    // Assume no such subarray exist and initialize
    d.low = -1;
    d.high = -1;
    // store sum till 0 elements as 0
    // required to handle case when entire array sums to 0
    sum_index[0] = 0;
    
    for(i=0;i<n;i++)
    {
        // add each element to sum
        sum=sum+elements[i];
        // if new sum is already in map then a subarray sums to zero
        // so find starting and end index
        if(sum_index.find(sum)!=sum_index.end())
        {            
            d.low = sum_index[sum]+1;
            d.high = i+1;            
        }        
        else
            // if new sum is not in map then store it in map
            sum_index[sum] = i+1;
    }       
        return d;   
}
int main()
{
    vector<int> elements;
    int n,ele,i;
    details d;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    d = find_zero_sum(elements);
    if(d.low==-1)
        cout<<-1;
    else
        cout<<d.low<<" "<<d.high<<endl;
}