#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point 
{
    int x, y;
};

bool compareByX(const Point &p1, const Point &p2) 
{
    if (p1.x == p2.x)
        return p1.y < p2.y;  
    return p1.x < p2.x;       
}

vector<Point> mergeMinimalPoints(const vector<Point> &leftResult, const vector<Point> &rightResult) 
{
    
    vector<Coordinate> mergedPoints;
    int index = 0;

    // Traverse both vectors to merge them while filtering dominated points
    for (const auto &leftPoint : leftPoints) 
    {
        // Advance the index while rightPoint is dominated
        while (index < rightPoints.size() && rightPoints[index].y >= leftPoint.y) 
        {
            index++;
        }
        // Add leftPoint to mergedPoints as it is not dominated
        mergedPoints.push_back(leftPoint);
    }

    // Append remaining rightPoints that are not dominated
    while (index < rightPoints.size()) 
    {
        mergedPoints.push_back(rightPoints[index]);
        index++;
    }

    // Filter out dominated points from the merged list
    vector<Coordinate> filteredPoints;
    int lowestY = 100000;

    for (const auto &point : mergedPoints) 
    {
        if (point.y < lowestY) 
        {
            filteredPoints.push_back(point);
            lowestY = point.y; // Update the lowest y encountered
        }
    }

    return filteredPoints;
}

vector<Point> findNonDominatingPoints(vector<Point> &points, int left, int right) 
{
    if (left == right) 
    {
        return {points[left]};
    }
    
    int mid = left + (right - left) / 2;

    vector<Point> leftResult = findNonDominatingPoints(points, left, mid);
    vector<Point> rightResult = findNonDominatingPoints(points, mid + 1, right);

    return mergeMinimalPoints(leftResult, rightResult);
}

int main() 
{
    vector<Point> points = {{1, 6}, {3, 5}, {2, 4}, {4, 3}, {5, 2}};
    
    sort(points.begin(), points.end(), compareByX);

    for (const auto &p : points)
    {
        cout << p.x << " " << p.y << endl;
    }

    vector<Point> minimalPoints = findNonDominatingPoints(points, 0, points.size() - 1);

    cout << "Non-dominating points (minimal points): " << endl;
    for (const Point &p : minimalPoints) 
    {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
