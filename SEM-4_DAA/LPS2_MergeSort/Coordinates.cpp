/*
(QS)
Given n 2-dimensional points (x1, y1), (x2, y2), . . . , (xn, yn), 
(a) arrange the n points in an increasing order of the x coordinates
(b) arrange the n points in an increasing order of the y coordinates
(c) arrange the n − points in decreasing order of the value (x −coordinate + y − coordinate)/2) coordinates. 

(code)
*/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

bool cmpX(Point p1, Point p2)
{
    return p1.x < p2.x;
}

bool cmpY(Point p1, Point p2)
{
    return p1.y < p2.y;
}

bool cmpXY(Point p1, Point p2)
{
    return (p1.x + p1.y) > (p2.x + p2.y);
}

vector<Point> mergeSort(vector<Point>& arr, int left, int right, bool (*cmp)(Point, Point))
{
    if (left == right)
    {
        vector<Point> result(1, arr[left]);
        return result;
    }
    int mid = (left + right) / 2;
    vector<Point> leftArr = mergeSort(arr, left, mid, cmp);
    vector<Point> rightArr = mergeSort(arr, mid + 1, right, cmp);
    vector<Point> result(leftArr.size() + rightArr.size());
    int i = 0, j = 0, k = 0;
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (cmp(leftArr[i], rightArr[j]))
        {
            result[k] = leftArr[i];
            i++;
        }
        else
        {
            result[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < leftArr.size())
    {
        result[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightArr.size())
    {
        result[k] = rightArr[j];
        j++;
        k++;
    }
    return result;
}

void sortByX(vector<Point>& arr)
{
    sort(arr.begin(), arr.end(), cmpX);
}

void sortByY(vector<Point>& arr)
{
    sort(arr.begin(), arr.end(), cmpY);
}

void sortByXY(vector<Point>& arr)
{
    vector<Point> sortedArr = mergeSort(arr, 0, arr.size() - 1, cmpXY);
    arr = sortedArr;
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> arr(n);
    cout << "Enter the coordinates of points: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    sortByX(arr);
    cout << "Sorted by x-coordinate: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].x << " " << arr[i].y << endl;

    sortByY(arr);
    cout << "Sorted by y-coordinate: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].x << " " << arr[i].y << endl;

    sortByXY(arr);
    cout << "Sorted by (x + y)/2: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].x << " " << arr[i].y << endl;

    return 0;
}
