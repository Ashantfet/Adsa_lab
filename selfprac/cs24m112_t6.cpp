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
    
    vector<Point> merging;
    int j = 0;

    // Process both vectors to merge them while maintaining minimality
    for (auto it = leftResult.begin(); it != leftResult.end(); ++it)
    {
        const auto &leftPoint = *it;
        // Remove any rightPoint that is dominated by the leftPoint
        while (j < rightResult.size() && rightResult[j].y >= leftPoint.y) 
        {
            j++;
        }
        // Add leftPoint to finalResult as it is not dominated
       merging.push_back(leftPoint);
    }

    // Add remaining rightPoints that are not dominated by any leftPoint
    while (j < rightResult.size()) 
    {
        merging.push_back(rightResult[j]);
        j++;
    }

    // Remove dominated points in finalResult
    vector<Point> final;
    int minimumy = 10000;

    for (auto it = finalResult.begin(); it != merging.end(); ++it)
    {
        const auto &finalpoint = *it;
        if (finalpoint.y < minimumy) 
        {
            final.push_back(it);
            minimumy = finalpoint.y; // Update minimum y
        }
    }

    return final;
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
