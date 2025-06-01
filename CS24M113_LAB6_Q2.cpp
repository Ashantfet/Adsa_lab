#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point 
{
    int x, y;
};
bool compareByX(const Point &a, const Point &b) 
{
    if (a.x == b.x)
        return a.y < b.y;  
    return a.x < b.x;       
}

//merge based on y-coordinates
vector<Point> mergeMinimalPoints(vector<Point> &leftSet, vector<Point> &rightSet) 
{
    vector<Point> temp;
    int rightIndex = 0;
    for ( Point &leftPoint : leftSet)   
    {
        while (rightIndex < rightSet.size() && rightSet[rightIndex].y >= leftPoint.y) 
        {
            rightIndex++;
        }
        temp.push_back(leftPoint);
    }
    while (rightIndex < rightSet.size()) 
    {
        temp.push_back(rightSet[rightIndex]);
        rightIndex++;
    }
    vector<Point> answer;
    int minimumy = 100000;
    for (auto &point : temp) 
    {
        if (point.y < minimumy) 
        {
            answer.push_back(point);
            minimumy = point.y;
        }
    }
    return answer;
}

// divide
vector<Point> findNonDominatingPoints(vector<Point> &points, int left, int right) 
{
    if (left == right) 
    {
        return {points[left]};
    }
    int mid = left + (right - left) / 2;
    vector<Point> leftPoints = findNonDominatingPoints(points, left, mid);
    vector<Point> rightPoints = findNonDominatingPoints(points, mid + 1, right);
    return mergeMinimalPoints(leftPoints, rightPoints);
}
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int numPoints;
        cin >> numPoints;
        vector<Point> points;
        while (numPoints--) 
        {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }
        sort(points.begin(), points.end(), compareByX);
        vector<Point> result = findNonDominatingPoints(points, 0, points.size() - 1);
        for (Point &p : result) 
        {
            cout << p.x << " " << p.y << endl;
        }
        cout << endl;
    }
    return 0;
}
