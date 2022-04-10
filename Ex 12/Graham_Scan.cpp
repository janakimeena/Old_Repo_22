#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<utility>
#include<math.h>
#include<algorithm>
/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
*/
// global variable to represent the first point
pair<float,float> bottom_left_most;
void read_points(vector<pair<float,float> > &points, int n)
{
    int i;
    pair<float, float> point;
    for(i=0;i<n;i++)
    {
        cin>>point.first>>point.second;
        points.push_back(point);
    }
}
void print_points(vector<pair<float,float> > points)
{
   for(auto point:points)
   {
       cout<<point.first<<" "<<point.second<<endl;
   }
}
// returns index of bottom most point
int find_bottom_most_point(vector<pair<float, float> > points)
{
    int bottom_most,i,n;
    bottom_most = 0;
    n = points.size();
    for(i=1;i<n;i++)
    {
        if(points[i].second<points[bottom_most].second)
            bottom_most = i;
        if((points[i].second==points[bottom_most].second)&&(points[i].first<points[bottom_most].first))
            bottom_most = i;
    }
    return bottom_most;
}

// 0 --> p0, p1 and p2 are collinear
// 1 --> p2 is to right of the line p0, p1 - imagine that you are 
// standing at point p1 facing opposite to p0 - cross product is -ve
// -1 --> Counterclockwise - cross product is +ve - turn left
int find_orientation(pair<float,float> p0,pair<float,float> p1, pair<float,float> p2)
{
    float cross_product;    
    cross_product = (p1.first - p0.first) * (p2.second - p0.second ) - 
                    (p1.second - p0.second) * (p2.first - p0.first);
    if(cross_product==0)
        return 0;
    return (cross_product<0)?1:-1;
}
float distance(pair<float,float> p1, pair<float,float> p2)
{
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)
                + (p1.second-p2.second)*(p1.second-p2.second));
}
// returns true if p2 is anticlockwise to p1 with respect to 
// p0 and if p1 and p2 are collinear then 
// returns true if p2 is farther from p0 point than p1
int compare(const pair<float,float> p1,const pair<float,float> p2)
{
    int orientation = find_orientation(bottom_left_most,p1,p2);
    if(orientation==0)
        return distance(bottom_left_most,p2)>=distance(bottom_left_most,p1);
    return(orientation==-1);
}

bool find_top_two(stack<pair<float,float> >&s, pair<float,float> &top, pair<float,float> &next_to_top)
{
    top = s.top();
    s.pop();
    next_to_top = s.top();
    s.pop();
}
void convex_Hull(vector<pair<float,float> > points,stack<pair<float,float> > &CH)
{
    int bottom_most;
    vector<pair<float,float> > diff_p0;
    pair<float,float> top, next_to_top;
    // find index of the bottom most point 
    // if there is a tie choose leftmost
    bottom_most = find_bottom_most_point(points);
    bottom_left_most = points[bottom_most];
    // make the bottom most point as first point
    // STL has got a built-in swap
    swap(points[0],points[bottom_most]);
    // if comparator function returns false then 
    // the elements will be swapped    
    sort(points.begin()+1,points.end(),compare);
    // print sorted points

    // push first three points into stack
    cout<<"Finished sorting\n";
    CH.push(points[0]);
    CH.push(points[1]);
    CH.push(points[2]);
    // take top and next to top
    
    for(int i=3;i<points.size();i++)
    {
        if(CH.size()<1)
            break;
        // take the point on the top of the stack and remove from stack
        top = CH.top();
        CH.pop();
        // check if the point at ith index is to right or left 
        // of the line formed with top two points in the stack
        // if ith point is to the right then pop the stack
        while(find_orientation(CH.top(),top,points[i])!=-1)
        {
            top = CH.top();
            CH.pop();
        }
        CH.push(top);
        CH.push(points[i]);
    }

}
void print_Convex_Hull(stack<pair<float,float> > CH)
{
    pair<float,float> point;
    while(!CH.empty())
    {
        //cout<<"print"<<endl;
        point = CH.top();
        cout<<point.first<<" "<<point.second<<endl;
        CH.pop();
    }
}
int main()
{
    vector<pair<float,float> > points;
    stack<pair<float,float> > CH;
    pair<float,float> point;
    int n;
   
    //read the points
    cin>>n;
    read_points(points,n);
    //print_points(points);
    convex_Hull(points,CH);  
    print_Convex_Hull(CH);
}
